#ifndef SHELL_H
#define SHELL_H

// Constants
#define MAX_INPUT_SIZE 1024
#define MAX_ARG_SIZE 100

// Function Declarations

// Main Shell Functions
char *read_input();
char **parse_input(char *input);
void execute_command(char **args);

// Redirection and Piping
int handle_redirection(char **args);
int handle_piping(char *input);

// Utility Functions
char **tokenize_input(const char *input, const char *delim);
char *trim_whitespace(char *str);

#endif
