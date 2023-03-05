#include "find_command.h"
#include "strncat.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <stddef.h>
#include <stdlib.h>
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
	char *directory, *command2;

	if (command[0] == '/')
	{
		s = stat(command, &statbuf);
		if (s == 0)
			return (command);
	}

	command2 = _strncat("/", command);

	while (node != NULL)
	{
		directory = node->directory;
		directory = _strncat(directory, command2);
		s = stat(directory, &statbuf);
		if (s == 0)
		{
			free(command);
			free(command2);
			return (directory);
		}
		node = node->next;
		free(directory);
	}
	errno = 2;

	free(command);
	free(command2);
	return (NULL);
}
