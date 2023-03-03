#include "main.h"

/**
  * _getenv - replicates the function of getenv
  * @name: name of the variable to get
  * @env: environment variables
  * Return: value of the variable or NULL on fail
  */
char *_getenv(const char *name, char **env)
{
    /* i,j aren't used outside of the for loop, they should be declared there. */
	int i, j;
    /* Don't cast a const char to a char when it's inside a function like this. */
    /* Also you don't need to here because you're not modifying name anyway. */
	char *entry = (char *) name;
    /* Variable also doesn't need to be in this scope */
	char *variable;

    /* should be int i = 0 */
	for (i = 0; env[i] != NULL; i++)
	{
        /* should be const char* variable = env[i] */
		variable = env[i];
        /* should be int j = 0 here. */
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
