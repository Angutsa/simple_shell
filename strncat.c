#include "main.h"
/**
 * _strncat - concatenates two strings
 * @str1: string 1
 * @str2: string 2
 * Return: concatenated string
 */
char *_strncat(char *str1, char *str2)
{
	char *dest = NULL;
	int len = 0, b = 0, n = 0;

	for (n = 0; str1[n] != '\0'; n++)
	{
		len++;
	}

	for (n = 0; str2[n] != '\0'; n++)
	{
		len++;
	}

	len++;
	dest = malloc(sizeof(char) * len);

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
