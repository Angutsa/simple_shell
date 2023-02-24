#include "main.h"

char *new_variable(char *name, char *value);
void overwrite(char **env, char *variable, char *new);
void add_value(char **env, char *new);


/**
  * _setenv - changes or adds an environment variable
  * @name: name of the variable to be added or changed
  * @value: value for the variable to be added or changed
  * @overwrite: int value specifying whether or not to overwrite
  * Return: 0 on success, -1 on error
  */
int _setenv(const char *name, const char *value, int overwrite)
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

	new = new_variable(name, value);
	variable = _getenv(argv[1]);

	if (variable == NULL)
	{
		add_value(env, new);
	}
	else if (overwrite != 0)
	{
		overwrite(env, variable, new);
	}
	return (0);
}

/**
  * new_variable - creates a "name=value" string for the new env. variable
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
	if (new == NULL)
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

/**
  * add_value - adds a new env variable
  * @env: pointer to array of environment variables
  * @new: "name=value" string for new environment variable
  */
void add_value(char **env, char *new)
{
	int i = 0;

	for(;;)
	{
		if (env[i] == NULL)
		{
			env[i] = new;
			env[i + 1] = NULL;
			break;
		}
		i++;
	}
}

/**
  * overwite - overwrites the environment variable
  * @env: pointer to array of environment variables
  * @variable: variable in env to be overwritten
  * @new: "name=value" string to replace current variable
  */
void overwrite(char **env, char *variable, char *new)
{
	int i, j;
	char *tmp = NULL;

	for (i = 0; env[i] != NULL; i++)
	{
		tmp = env[i];
		for (j = 0; tmp[j] != '='; j++)
		{
			if (tmp[j] != variable[j])
				break;
		}
		if(tmp[j] == '=')
			break;
	}
	env[i] = new;
}
