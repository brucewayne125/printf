#include "main.h"

int _printf(const char *format, ...)
{
	va_list args;
	int count = 0;
	char buffer[1024];
	int i = 0, j = 0;

	va_start(args, format);
	while (format && format[i])
	{
		if (format[i] == '%')
		{
			i++;
			if (format[i] == 'c')
				count += print_char(va_arg(args, int));
			else if (format[i] == 's')
				count += print_string(va_arg(args, char *));
			else if (format[i] == '%')
				count += write(1, "%", 1);
			else if (format[i] == 'b')
				count += print_binary(va_arg(args, unsigned int));
			else if (format[i] == 'u')
				count += print_unsigned(va_arg(args, unsigned int));
			else if (format[i] == 'o')
				count += print_octal(va_arg(args, unsigned int));
			else if (format[i] == 'x' || format[i] == 'X')
				count += print_hex(va_arg(args, unsigned int), format[i]);
			else
				count += write(1, &format[i], 1);
		}
		else
		{
			buffer[j++] = format[i];
			if (j >= 1024)
			{
				write(1, buffer, j);
				j = 0;
			}
		}
		i++;
	}
	if (j > 0)
		write(1, buffer, j);
	va_end(args);
	return (count);
}

