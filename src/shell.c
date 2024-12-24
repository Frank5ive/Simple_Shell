#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include "shell.h"

// Function to read input from the user
char *read_input() {
    char *input = malloc(MAX_INPUT_SIZE);
    if (!input) {
        perror("Malloc failed");
        exit(EXIT_FAILURE);
    }

    // Prompt and read input
    if (fgets(input, MAX_INPUT_SIZE, stdin) == NULL) {
        free(input);
        return NULL;
    }

    // Remove the newline character
    input[strcspn(input, "\n")] = '\0';

    // Return input only if not empty
    if (strlen(input) == 0) {
        free(input);
        return NULL;
    }
    return input;
}

// Function to parse the input into arguments
char **parse_input(char *input) {
    if (!input) {
        return NULL;
    }

    // Trim whitespace from the input
    input = trim_whitespace(input);

    // Tokenize the input using spaces as the delimiter
    return tokenize_input(input, " ");
}

// Function to execute a command
void execute_command(char **args) {
    if (args[0] == NULL) {
        printf("No command entered.\n");
        return;
    }

    if (strcmp(args[0], "exit") == 0) {
        printf("Exiting Simple Shell...\n");
        exit(EXIT_SUCCESS);
    }

    // Check if the input contains pipes
    if (handle_piping(args[0])) {
        return;  // Piping handled
    }

    pid_t pid = fork();
    if (pid == -1) {
        perror("Failed to fork");
        return;
    } 
    else if (pid == 0) {  // Child process
        if (handle_redirection(args) == -1) {
            exit(EXIT_FAILURE);  // Handle redirection failure
        }

        if (execvp(args[0], args) == -1) {
            perror("Command execution failed");
        }
        exit(EXIT_FAILURE);  // Ensure child exits after failure
    } 
    else {  // Parent process
        int status;
        waitpid(pid, &status, WUNTRACED);
    }
}
