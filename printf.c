#include "main.h"

/**
  * _printf - prints out a string
  * @str: string to print out
  */
void _printf(char *str)
{
	int i = 0;

	for (i = 0; str[i] != '\0'; i++)
	{
        /* use STDOUT_FILENO */
		write(1, &(str[i]), 1);
	}
}
