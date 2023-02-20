#ifndef MAIN_H

#define MAIN_H

#include <stdio.h>
#include <stddef.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>
#include <stdlib.h>
#include <sys/stat.h>

char *get_user_input(void);
void get_arguments(char **arguments, char *input);

/**** OLD ****/
void start_simple_shell();
void fork_wait_exec();
char **separate_string(char *s);
char **create_argv(char *argv);
char *_getenv(const char *name);
int _unsetenv(const char *name);

#endif
