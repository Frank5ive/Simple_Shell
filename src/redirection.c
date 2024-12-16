#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include "shell.h"

// Function to handle redirection
int handle_redirection(char **args) {
    int fd;
    int i = 0;

    while (args[i] != NULL) {
        if (strcmp(args[i], ">") == 0) {  // Output Redirection
            if (args[i + 1] == NULL) {
                fprintf(stderr, "Error: No file specified for output redirection.\n");
                return -1;
            }
            fd = open(args[i + 1], O_WRONLY | O_CREAT | O_TRUNC, 0644);
            if (fd == -1) {
                perror("Failed to open file for output");
                return -1;
            }
            dup2(fd, STDOUT_FILENO);  // Redirect standard output
            close(fd);
            args[i] = NULL;  // Remove redirection token
        } 
        else if (strcmp(args[i], "<") == 0) {  // Input Redirection
            if (args[i + 1] == NULL) {
                fprintf(stderr, "Error: No file specified for input redirection.\n");
                return -1;
            }
            fd = open(args[i + 1], O_RDONLY);
            if (fd == -1) {
                perror("Failed to open file for input");
                return -1;
            }
            dup2(fd, STDIN_FILENO);  // Redirect standard input
            close(fd);
            args[i] = NULL;  // Remove redirection token
        }
        i++;
    }
    return 0;
}
