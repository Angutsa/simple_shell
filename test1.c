#include "main.h"

/**
  * create_argv - generates array of argv elements
  * @argv: string entered by the user after the command
  * Description: create_argv() creates an array of command arguments
  * from the string argv. argv should be the user's command arguments
  * supplied at command entry.
  * Return: array of strings where each string is each word in argv
  */
char **create_argv(char *argv)
{
	size_t x = 10;
	int n = 0, words = 0, i = 0;
	char *input = NULL;
	char *string[10];
	char *delim = " ";

	input = malloc(sizeof(char) * x);
	if (input == NULL)
	{
		return (-1);
	}

	printf("~$");

	n = getline(&input, &x, stdin);
	if (n == -1)
		printf("Error!\n");

	//Separates entry string into words
	string[0] = strtok(input, delim);
	i++;
	if (*(string[0]) == '\n')
		return (0);

	for(;;)
	{
		string[i] = strtok(NULL, delim);
		if (string[i] == NULL)
			break;
		i++;
	}

	free(input);
	return (0);
}
