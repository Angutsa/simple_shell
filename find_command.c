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
            /* Don't free your input parameters */
            /* free(command); */
            /* First see my comment in simple.c about double free. */
            /* The problem with 'free' by itself is that it's hard to "just know" what's being free'd */
            /* Per my other comment, if you had a _strncat_free then you know that this free is associated with a previous strncat call. */
            /* Even if it's just a macro for free */
			free(command2);
			return (directory);
		}
		node = node->next;
		free(directory);
	}
	errno = 2;

    /* Don't free your input parameters (The exception is if the function is named "free" or "cleanup" or some thing where the caller knows it's going to free the input parameters. This led you to a double free exception. */
    /* free(command); */
	free(command2);
	return (NULL);
}
