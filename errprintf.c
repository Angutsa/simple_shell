#include "main.h"

/**
  * errprintf - prints out a string to stderr
  * @str: string to print out
  */
void errprintf(char *str)
{
	int i = 0;

	for (i = 0; str[i] != '\0'; i++)
	{
		write(2, &(str[i]), 1);
	}
}
