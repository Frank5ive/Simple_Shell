#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "shell.h"

int main() {
    printf("Welcome to Simple Shell!\n");

    // Main loop
    while (1) {
        printf("simple_shell> ");
        char *input = read_input();

        if (input == NULL) {
            printf("Error reading input.\n");
            continue;
        }

        // Parse and handle commands
        char **args = parse_input(input);
        if (args[0] != NULL) {
            execute_command(args);
        } else {
            printf("No command entered.\n");
        }

        free(input);
        free(args);
    }

    return 0;
}
