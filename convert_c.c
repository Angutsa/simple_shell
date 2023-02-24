#include "main.h"

/**
  * convert_c - handles the format specifier for char
  * @ptr: va_list from printf
  * Return: number of characters printed
  */
int convert_c(va_list ptr)
{
	int count = 0;

	_putchar(va_arg(ptr, int));
	count++;
	return (count);
}
