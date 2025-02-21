#ifndef SHELL_H
#define SHELL_H

// Function declarations
void shell_loop(void);
char *shell_read_line(void);
char **shell_split_line(char *line);
int shell_execute(char **args);
int shell_run(char **args);

#endif
