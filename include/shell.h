#ifndef SHELL_H
#define SHELL_H

// Function declarations
char *read_input();
char **parse_input(char *input);
void execute_command(char **args);

#endif
