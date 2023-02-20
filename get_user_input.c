#include "main.h"

/**
  * get_user_input - gets the user's input
  * Return: the text typed in by the user and stripped of the newline
  * character, or NULL on error
  */
char *get_user_input(void)
{
	char *input = NULL;
	int n = 0;
	size_t x = 0;

	input = malloc(sizeof(char) * x);
	if (input == NULL)
	{
		perror("./hsh");
		return (NULL);
	}

	printf("#cisfun$ ");

	n = getline(&input, &x, stdin);
	if (n == -1)
	{
		perror("./hsh");
		return (NULL);
	}

	/* Strip newline character */
	if (input[n - 1] == '\n')
		input[n - 1] = '\0';

	return (input);
}
