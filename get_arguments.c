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
	char *delim = " ", *input = NULL;
    /* rename n to result */
	int n = 0, i;
	size_t x = 0;

	errno = 0;

	n = getline(&input, &x, stdin);
	if (n == -1)
	{
        /* I don't think you need to check errno because the fact that getline
           returned -1 means it set errno to something. */
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

    /* Doesn't check if this value is null.
       Your program crashes if you just press space then enter at the shell. */
	arguments[0] = strtok(input, delim);
	i = 1;
	for (;;)
	{
		arguments[i] = strtok(NULL, delim);
		if (arguments[i] == NULL)
			break;
		i++;
	}
    /* You didn't free(input).
       strtok operates on the same memory input is pointing to.
       So your arguments are all pointers to the memory allocated by getline.
       Where is it free'd? */

	return (0);
}
