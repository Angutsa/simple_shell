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
#include <signal.h>
#include <stdarg.h>

/** Structs **/
/**
  * struct path - struct for a directory in PATH
  * @directory: directory in PATH
  * @next: pointer to the next directory
  */
struct path
{
	char *directory;
	struct path *next;
};

int get_arguments(char **arguments, char *input, char *progname);
char *_getenv(const char *name, char **env);
struct path *link_path(char **env);
char *_strncat(char *dest, char *src);
char *find_command(char *command, struct path *path_head);
void _printf(char *str);

#endif
