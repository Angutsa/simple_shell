#include "main.h"

/**
  * get_arguments - reads user input and generates command-line arguments
  * @arguments: pointer to arguments string
  * @input: user input
  * Return: 0 on success, -1 on EOF, 1 on empty entry, 2 on error
  */
int get_arguments(char **arguments, char *input)
{
	char *delim = " ";
	int n = 0, i;
	size_t x = 0;

	n = getline(&input, &x, stdin);
	if (input[0] == '\0')
		return (-1);

	if (n == -1)
	{
		perror("./hsh");
		return (2);
	}

	/* Strip newline character */
	i = 1;
	if (input[n - i] == '\n')
		input[n - i] = '\0';

	if (input[0] == '\0')
		return (1);

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
