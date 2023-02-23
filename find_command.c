#include "main.h"
#include <dirent.h>
#include <errno.h>

/**
  * find_command - looks for the command through PATH
  * @command: command to find
  * @path_head: pointer to the head of the PATH linked list
  * Return: full command name or NULL if not found
  */
char *find_command(char *command, struct path *path_head)
{
	struct stat statbuf;
	struct path *node = path_head;
	int s;
	char *directory;

	if (command[0] == '/')
	{
		s = stat(command, &statbuf);
		if (s == 0)
			return (command);
	}

	command = _strncat("/", command);

	while (node != NULL)
	{
		directory = node->directory;
		directory = _strncat(directory, command);
		s = stat(directory, &statbuf);
		if (s == 0)
			return (directory);
		node = node->next;
	}
	errno = 2;
	return (NULL);
}
