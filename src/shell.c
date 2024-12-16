#include <stdio.h>
#include <stdlib.h>
#include <string.h>
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

    if (fgets(input, MAX_INPUT_SIZE, stdin) == NULL) {
        free(input);
        return NULL;
    }

    // Remove the newline character
    input[strcspn(input, "\n")] = '\0';
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
        args[index++] = token;
        token = strtok(NULL, " ");
    }
    args[index] = NULL; // Terminate argument list
    return args;
}

// Function to execute a command
void execute_command(char **args) {
    printf("Executing command: %s\n", args[0]);
}
