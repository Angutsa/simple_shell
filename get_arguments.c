#include "main.h"

/**
  * get_arguments - separates user input into relevant arguments
  * @arguments: array to put the arguments in
  * @input: user input
  */
void get_arguments(char **arguments, char *input)
{
	char *delim = " ";
	int i;

	arguments[0] = strtok(input, delim);
	i = 1;
	for(;;)
	{
		arguments[i] = strtok(NULL, delim);
		if (arguments[i] == NULL)
			break;
		i++;
	}
}
