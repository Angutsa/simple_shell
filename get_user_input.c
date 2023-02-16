#include "main.h"

/**
  * get_user_input - gets the user's input from stdin
  */
void get_user_input()
{
	size_t x = 1;
	int n = 0;
	char *input = NULL;

	input = malloc(sizeof(char) * x);
	if (input == NULL)
		return (-1);

	printf("$");

	n = getline(&input, &x, stdin);
	if (n == -1)
		printf("Error!\n");

	printf("%s", input);

	free(input);
	return (0);
}
