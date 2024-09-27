#include "main.h"

/**
 * _printf - displays output according to the format
 * @format: format string
 *
 * Return: return number of characters
 */
int _printf(const char *format, ...)
{
	int count = 0;
	char c;
	va_list args;

	va_start(args, format);
	
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			if (*format == 'c')
			{
				c = (char)va_arg(args, int);
				count += write(1, &c, 1);
			}
			else if (*format == 's')
			{
				char *str = va_arg(args, char *);

				while (*str)
				{
					count += write(1, str, 1);
					str++;
				}
			}
			else if (*format == '%')
			{
				count += write(1, "%", 1);
			}
		}
		else
		{
			count += write(1, format, 1);
		}
		format++;
	}
	va_end(args);
	return (count);
}
