#include "main.h"
/**
  * _unsetenv - deletes the variable name from the environment
  * @name: name of the variable to delete
  * Return: 0 on success, -1 on failure
  */
int _unsetenv(const char *name)
{
	int i, j;
	char *tmp = NULL;

	if (_getenv(name) == NULL)
		return (0);

	for (i = 0; env[i] != NULL; i++)
	{
		tmp = env[i];

		for (j = 0; tmp[j] == name[j]; j++)
		{
			if (tmp[j] == '=' && name[j] == '\0')
				break;

			if (tmp[j] == '\0' || name[j] == '\0')
			{
				j = 0;
				break;
			}
		}

		if (j != 0)
			break;
	}

	while(env[i] != NULL)
	{
		env[i] = env[i + 1];
		i++;
	}

	return (0);
}
