#define _POSIX_C_SOURCE 200809L
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "shell.h"

// Function to remove leading and trailing whitespace
char *trim_whitespace(char *str) {
    if (str == NULL) {
        return NULL;
    }

    // Remove leading whitespace
    while (isspace((unsigned char)*str)) {
        str++;
    }

    // If all spaces, return an empty string
    if (*str == '\0') {
        return str;
    }

    // Remove trailing whitespace
    char *end = str + strlen(str) - 1;
    while (end > str && isspace((unsigned char)*end)) {
        end--;
    }

    // Null-terminate the trimmed string
    *(end + 1) = '\0';

    return str;
}

// Function to tokenize input into an array of strings
char **tokenize_input(const char *input, const char *delim) {
    if (input == NULL || delim == NULL) {
        return NULL;
    }

    // Duplicate the input string since strtok modifies it
    char *input_copy = strdup(input);
    if (!input_copy) {
        perror("strdup failed");
        exit(EXIT_FAILURE);
    }

    // Allocate memory for token array
    char **tokens = malloc(MAX_ARG_SIZE * sizeof(char *));
    if (!tokens) {
        perror("malloc failed");
        free(input_copy);
        exit(EXIT_FAILURE);
    }

    int index = 0;
    char *token = strtok(input_copy, delim);

    while (token != NULL && index < MAX_ARG_SIZE - 1) {
        tokens[index++] = strdup(token); // Duplicate each token
        token = strtok(NULL, delim);
    }
    tokens[index] = NULL; // Null-terminate the token array

    free(input_copy);
    return tokens;
}
