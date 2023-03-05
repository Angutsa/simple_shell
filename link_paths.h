#ifndef LINK_PATHS_H

#define LINK_PATHS_H

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


struct path *add_to_linked_list(char *variable, struct path *node);
struct path *link_path(char **env);

#endif
