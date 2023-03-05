#ifndef SIMPLE_SHELL_H

#define SIMPLE_SHELL_H

#define MAX_ARGS 100

#include "link_paths.h"

void free_path(struct path *node);
void execute_command(char *progname, char *arguments[], char **env);

#endif
