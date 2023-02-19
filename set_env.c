#include "main.h"

/**
  * main - prints directories in PATH
  * @TODO:
  * Return: TODO
  */
int main(int argc, char **argv, char **env)
{
	char *variable = NULL, *new = NULL;
	int i, count = 0;

	for (i = 0; name[i] != '\0'; i++)
	{
		count++;
	}

	for (i = 0; value[i] != '\0'; i++)
	{
		count++;
	}
	count += 2; /* Add space for \0 and = */

	new = malloc(sizeof(char) * count);
	if (new == NULL)
		return (-1);


	variable = _getenv(argv[1]);
	if (variable == NULL)
	{
		/* TODO: Implement handling if variable does not exist*/
	}
	else
	{
		

		/* TODO: Implement handling if variable is present*/
	}

	return (0);
}

/**
  * new_variable - creates a string entry for the new env. variable
  * @name: name of the variable
  * @value: value of the variable
  * Return: Returns a pointer to the new variable string
  */
char *new_variable(char *name, char *value)
{
	int i, j, count = 0;
	char *new = NULL;

	for (i = 0; name[i] != '\0'; i++)
	{
		count++;
	}

	for (i = 0; value[i] != '\0'; i++)
	{
		count++;
	}
	count += 2; /* Add space for \0 and = */

	new = malloc(sizeof(char) * count);
	if (new = NULL)
		return (NULL);

	for (i = 0; name[i] != '\0'; i++)
	{
		new[i] = name[i];
	}

	new[i] = '=';

	for (j = 0, i++; value[j] != '\0'; j++, i++)
	{
		new[i] = value[j];
	}

	new[i] = '\0';

	return (new);
}
