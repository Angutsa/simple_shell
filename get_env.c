#include "get_env.h"
#include <stddef.h>

/**
  * _getenv - replicates the function of getenv
  * @name: name of the variable to get
  * @env: environment variables
  * Return: value of the variable or NULL on fail
  */
char *_getenv(const char *name, char **env)
{
	int i, j;
	char *entry = (char *) name;
	char *variable;

	for (i = 0; env[i] != NULL; i++)
	{
		variable = env[i];
		j = 0;
		for (;;)
		{
			if (variable[j] == '=' && entry[j] == '\0')
			{
				variable = &variable[j + 1];
				return (variable);
			}

			if (entry[j] != variable[j])
				break;

			if (entry[j] == '\0')
				break;
			j++;
		}
	}
	return (NULL);
}
