#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include "shell.h"

#define MAX_INPUT_SIZE 1024
#define MAX_ARGS 64

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
    char **args = malloc(MAX_ARGS * sizeof(char *));
    if (!args) {
        perror("Malloc failed");
        exit(EXIT_FAILURE);
    }

    int index = 0;
    char *token = strtok(input, " ");
    while (token != NULL && index < MAX_ARGS - 1) {
        // Manually duplicate the token
        args[index] = malloc(strlen(token) + 1);
        if (!args[index]) {
            perror("Malloc failed");
            exit(EXIT_FAILURE);
        }
        strcpy(args[index++], token); // Copy the token into args
        token = strtok(NULL, " ");
    }
    args[index] = NULL; // Terminate argument list
    return args;
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
