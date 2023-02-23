#include "main.h"
#include <errno.h>

/**
  * get_arguments - reads user input and generates command-line arguments
  * @arguments: pointer to arguments string
  * @progname: name of the program
  * Return: 0 on success, -1 on EOF, 1 on empty entry
  */
int get_arguments(char **arguments, char *progname)
{
	char *delim = " ", *input = " ";
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

	/* Strip newline character */
	i = 1;
	if (input[n - i] == '\n')
		input[n - i] = '\0';

	if (input[0] == '\0')
	{
		free(input);
		return (1);
	}

	/* Get arguments*/
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
