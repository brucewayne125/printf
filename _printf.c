#include "main.h"

int _printf(const char *format, ...)
{
	int count = 0;
	va_list args_list;

	va_start(args_list, format);

	while(*format)
	{
		if(*format == '%')
		{
			format++;
			if(*format == 'c')
			{
				char c = (char)va_arg(args_list, int);
				count += write(1, &c, 1);				
			}
			else if (*format == 's')
			{
				char *s = va_arg(args_list, char *);
				if(s == NULL)
					s = "(null)";
				count += write(1, s, strlen(s));
			}
			else if (*format == '%')
			{
				count += write(1, "%", 1);
			}
			else
			{
				count += write(1, "%", 1);
				count += write(1, format, 1);
			}
		}
		else
		{
			count += write(1, format, 1);
		}
		format++;
	}
	va_end(args_list);
	return count;
}
