#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "shell.h"

int main() {
    printf("Welcome to Simple Shell!\n");

    while (1) {  // Main loop to keep shell running
        printf("simple_shell> ");

        // Read user input
        char *input = read_input();

        if (input == NULL) {
            printf("Error reading input.\n");
            continue;
        }

        // Parse the input into arguments
        char **args = parse_input(input);

        // Execute the command if valid
        if (args[0] != NULL) {
            execute_command(args);
        } else {
            printf("No command entered.\n");
        }

        // Free allocated memory
        free(input);
        free(args);
    }

    return 0;
}
