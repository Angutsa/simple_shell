#include <errno.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "get_arguments.h"

/**
  * get_arguments - reads user input and generates command-line arguments
  * @arguments: pointer to arguments string
  * @progname: name of the program
  * Return: 0 on success, -1 on EOF, 1 on empty entry
  */
int get_arguments(char **arguments, char *progname)
{
	char *delim = " ", *input = NULL;
	int n = 0, i;
	size_t x = 0;

	errno = 0;

	n = getline(&input, &x, stdin);
	if (n == -1)
	{
		if (errno != 0)
			perror(progname);
		free(input);
		return (-1);
	}

	if (input[0] == '\n')
	{
		free(input);
		return (1);
	}

	/* Strip newline character */
	input[n - 1] = '\0';

	arguments[0] = strtok(input, delim);
	i = 1;
	for (;;)
	{
		arguments[i] = strtok(NULL, delim);
		if (arguments[i] == NULL)
			break;
		i++;
	}

	return (0);
}
