#include "main.h"

int larger_than_ten(int num);

/**
  * convert_d - handles the format specifier for numbers ie. %d and %i
  * @ptr: va_list from printf
  * Return: number of characters printed
  */
int convert_d(va_list ptr)
{
	int x = va_arg(ptr, int);
	int count = 0;

	if (x < 0)
	{
		_putchar('-');
		count++;
		x = x * -1;
	}

	if (x < 9 && x >= 0)
	{
		_putchar(48 + x);
		count++;
	}
	else if (x >= 10)
	{
		count += larger_than_ten(x);
	}

	return (count);
}

/**
  * larger_than_ten - handles printing of numbers larger than 10
  * @num: number to print
  * Return: returns the number of characters printed
  */
int larger_than_ten(int num)
{
	int i, count = 0;

	i = num % 10;
	num = num / 10;
	if (num >= 10)
	{
		larger_than_ten(num);
	}
	else
	{
		_putchar(48 + num);
		count++;
	}

	_putchar(48 + i);
	count++;
	return (count);
}
