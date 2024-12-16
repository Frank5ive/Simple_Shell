#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include "shell.h"

// Function to handle piped commands
int handle_piping(char *input) {
    char *commands[MAX_ARG_SIZE];
    int num_commands = 0;

    // Split input by pipe symbol '|'
    char *cmd = strtok(input, "|");
    while (cmd != NULL && num_commands < MAX_ARG_SIZE - 1) {
        commands[num_commands++] = cmd;
        cmd = strtok(NULL, "|");
    }
    commands[num_commands] = NULL;

    if (num_commands < 2) {
        return 0;  // No pipe found
    }

    int pipe_fds[2], prev_fd = 0;

    for (int i = 0; i < num_commands; i++) {
        pipe(pipe_fds);  // Create a pipe

        pid_t pid = fork();
        if (pid == -1) {
            perror("Failed to fork");
            return -1;
        } else if (pid == 0) {  // Child process
            // Connect previous command output to current input
            if (prev_fd != 0) {
                dup2(prev_fd, STDIN_FILENO);
                close(prev_fd);
            }

            // If not the last command, redirect output to pipe
            if (i != num_commands - 1) {
                dup2(pipe_fds[1], STDOUT_FILENO);
            }
            close(pipe_fds[0]);
            close(pipe_fds[1]);

            // Parse and execute the command
            char **args = parse_input(commands[i]);
            if (execvp(args[0], args) == -1) {
                perror("Command execution failed");
                exit(EXIT_FAILURE);
            }
        } else {  // Parent process
            wait(NULL);
            close(pipe_fds[1]);
            prev_fd = pipe_fds[0];  // Set input for the next command
        }
    }
    return 1;  // Piping handled
}
