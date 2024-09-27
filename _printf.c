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
			else if (*format == 'd'|| *format == 'i')
			{
				int number = va_arg(args_list, int);
				print_num(number);
				count += (number < 0) ? 1 : 0;
				
				if (number == 0)
				{
				       	count += 1;
				}
				else
				{
					int n = number < 0 ? -number : number;
					while (n > 0)
					{
						n /= 10;
						count++;

					}
				}
			}
			else if (*format == 'b')
			{
				unsigned int number = va_arg(args_list, unsigned int);
				count += print_binary(number);
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

int print_binary(unsigned int n)
{
	char digit;
	
	if (n > 1)
		print_binary(n >> 1);
	
	digit = (n & 1) + '0';
	return write(1, &digit, 1);
}
