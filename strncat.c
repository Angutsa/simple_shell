#include "main.h"
/**
 * _strncat - concatenates two strings
 * @str1: string 1
 * @str2: string 2
 * Return: concatenated string that needs to be free'd
 */
char *_strncat(char *str1, char *str2)
{
    /* Same as other "declare at top of function" comments. */
    /* Declare & assign where they are needed */
	char *dest = NULL;
	int len = 0, b = 0, n = 0;

    /* Why not use strlen? Is that because it's not listed in limitations.txt? */
	for (n = 0; str1[n] != '\0'; n++)
	{
		len++;
	}

    /* You could have wrote your own strlen like you wrote your own strcat */
	for (n = 0; str2[n] != '\0'; n++)
	{
		len++;
	}

	len++;
	dest = malloc(sizeof(char) * len);
	if (dest == NULL)
	{
		perror("Error!");
		exit(EXIT_FAILURE);
	}

    /* same comment as above, but with strcpy */
	for (n = 0, b = 0; str1[n] != '\0'; n++, b++)
	{
		dest[b] = str1[n];
	}

	for (n = 0; str2[n] != '\0'; n++, b++)
	{
		dest[b] = str2[n];
	}

	dest[len - 1] = '\0';

	return (dest);
}
