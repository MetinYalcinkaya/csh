#include <unistd.h>

/*
   Function declarations
*/
// int shell_cd(char **args);
// int shell_exit(char **args);

// TODO: dynamically get amount of builtins
char *builtin_str[] = {"cd", "exit"};

int (*builtin_func[])(char **) = {
    // &shell_cd,
    // &shell_exit
};

int shell_num_builtins() { return sizeof(builtin_str) / sizeof(char *); }
