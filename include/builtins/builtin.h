#ifndef BUILTIN_H
#define BUILTIN_H

extern char *builtin_str[];
extern int (*builtin_func[]) (char **);
int shell_num_builtins(void);

#endif
