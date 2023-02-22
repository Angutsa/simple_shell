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
int num_len(int num);
char *_itoa(int num);
int create error(char **args, int err);
char *fill_path_dir(char *path);
list_t *get_path_dir(char *path);
char *get_location(char *command);
int shellby_alias(char **args, char __attribute__((__unused__)) **front);
void set_alias(char *var_name, char *value);
void print_alias(alias_t *alias);
int shellby_env(char **args, char __attribute__((__unused__)) **front);
int shellby_setenv(char **args, char __attribute__((__unused__)) **front);
int shellby_unsetenv(char **args, char __attribute__((__unused__)) **front);
int (*get_builtin(char *command))(char **args, char **front);
int shellby_exit(char **args, char **front);
int shellby_cd(char **args, char __attribute__((__unused__)) **front);
int shellby_help(char **args, char __attribute__((__unused__)) **front);


#endif
