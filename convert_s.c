#include "main.h"

/**
  * convert_s - handles the format specifier for string
  * @ptr: va_list from printf
  * Return: number of characters printed
  */
int convert_s(va_list ptr)
{
	int count = 0, i = 0;
	char *s = va_arg(ptr, char *);

	if (s == NULL)
		s = "(null)";


	for (; s[i] != '\0'; i++)
	{
		_putchar(s[i]);
		count++;
	}
	return (count);
}
