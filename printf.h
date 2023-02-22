#ifndef PRINTF_H

#define PRINTF_H

/** declarations **/
void _putchar(char c);
int _printf(const char *format, ...);
int convert_c(va_list ptr);
int convert_s(va_list ptr);
int convert_d(va_list ptr);
int handle_specifier(char c, va_list ptr);

#endif
