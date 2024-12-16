#ifndef SHELL_H
#define SHELL_H

#define MAX_INPUT_SIZE 1024
#define MAX_ARG_SIZE 100

// Function Declarations
char *read_input();
char **parse_input(char *input);
void execute_command(char **args);
int handle_redirection(char **args);

#endif
