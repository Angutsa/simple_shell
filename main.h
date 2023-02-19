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

void start_simple_shell();
void get_user_input();
void fork_wait_exec();
char **separate_string(char *s);
char **create_argv(char *argv);
char *_getenv(const char *name);

#endif
