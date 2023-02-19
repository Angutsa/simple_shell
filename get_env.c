#include "main.h"

extern char **environ;

/**
  * _getenv - replicates the function of getenv
  * @entry: variable
  * Return: variable itself (name & value) or NULL on fail
  */
char *_getenv(const char *name)
{
	int i, j;
	char **env = environ;
	char *entry = (char *) name;

	for (i = 0; env[i] != NULL; i++)
	{
		char *variable = env[i];
		j = 0;
		for(;;)
		{
			if (variable[j] == '=')
				return (variable);

			if (entry[j] != variable[j])
				break;

			if (entry[j] == '\0')
				break;
			j++;
		}
	}
	return (NULL);
}
