#include "builtins/builtin.h"
#include "shell.h"
#include <stdio.h>
#include <stdlib.h>
// Function declarations
void shell_loop(void);
char *shell_read_line(void);
char **shell_split_line(char *line);
int shell_execute(char **args);
int shell_run(char **args);

// Program start
int main(int argc, char **argv) {
  shell_loop();
  return EXIT_SUCCESS;
}
