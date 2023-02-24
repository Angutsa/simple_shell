#include <unistd.h>

/**
  * _putchar - writes a single character to stdout
  * @c: character to write
  */
void _putchar(char c)
{
	write(1, &c, 1);
}
