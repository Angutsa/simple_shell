#include "main.h"

/**
  * separate_string - separates a string into words
  * @s: string to be separated
  * Return: array of strings where each string is each word in s
  */
char **separate_string(char *s)
{
	size_t x = 10;
	int n = 0, words = 0, i = 0;
	char *string[10];
	char *delim = " ";

	//Separates entry string into words
	string[0] = strtok(s, delim);
	i++;
	if (*(string[0]) == '\n')
		return (NULL);

	for(;;)
	{
		string[i] = strtok(NULL, delim);
		if (string[i] == NULL)
			break;
		i++;
	}

	return (string);
}
