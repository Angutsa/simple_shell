#include "main.h"

/**
  * handle_specifier - prints the formatted string
  * @c: identifier
  * @ptr: va_list of the printf function
  * TODO: Handle flag characters, field width, precision, length modifiers
  * and buffers
  * Return: returns the number of characters printed on success and
  * returns -1 on failure i.e. identifier not found.
  */
int handle_specifier(char c, va_list ptr)
{
	int count = 0;

	switch (c)
	{
	case 'c':
		count = convert_c(ptr);
		break;
	case 's':
		count = convert_s(ptr);
		break;
	case 'd':
	case 'i':
		count = convert_d(ptr);
		break;
	default:
		return (-1);
	}

	return (count);
}
