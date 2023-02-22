#include "main.h"

void convert_percent(int *count, int *i, const char *format, va_list ptr);

/**
  * _printf - produces output according to a format
  * @format: character string to format and output
  * Return: number of characters printed excluding the null byte
  */
int _printf(const char *format, ...)
{
	va_list ptr;
	int i = 0, count = 0;

	if (format == NULL)
		return (-1);

	if (format[0] == '%' && format[1] == '\0')
		return (-1);

	va_start(ptr, format);

	for (; format[i] != '\0'; i++)
	{
		if (format[i] != '\\' && format[i] != '%')
		{
			_putchar(format[i]);
			count++;
		}
		else if (format[i] == '%')
		{

			convert_percent(&count, &i, format, ptr);
		}
	}

	va_end(ptr);
	return (count);
}
/**
  * convert_percent - handles the % character in the string
  * @count: pointer to number of chars printed
  * @i: pointer to position in the format string
  * @format: string to be formatted
  * @ptr: list of additional arguments
  */
void convert_percent(int *count, int *i, const char *format, va_list ptr)
{
	int tmp = 0;

	if (format[*i + 1] == '%')
	{
		_putchar('%');
		*count = *count + 1;
		*i = *i + 1;
		return;
	}

	if (format[*i + 1] == '\0')
		return;

	tmp = handle_specifier(format[*i + 1], ptr);
	if (tmp == -1)
	{
		_putchar(format[*i]);
		*count = *count + 1;
		return;
	}

	*count = tmp + *count;
	*i = *i + 1;
}
