#include "main.h"

/**
  * main - TODO
  * Return: Always 0
  */
int main (int argc, char **argv, char **env)
{
	int i, j;
	char *entry;

	if (argc != 2)
	{
		printf("Usage: %s _environmentvariable_\n", argv[0]);
		return (-1);
	}

	entry = argv[1];

	for (i = 0; env[i] != NULL; i++)
	{
		char *variable = env[i];
		j = 0;
		for(;;)
		{
			if (variable[j] == '=')
			{
				printf("%s\n", variable);
				return (0);
			}

			if (entry[j] != variable[j])
				break;

			if (entry[j] == '\0')
				break;
			j++;
		}
	}
	printf("Variable not found\n");
	return (-1);
	
}
