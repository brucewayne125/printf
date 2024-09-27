#include "main.h"

int print_char(char c)
{
	return (write(1, &c, 1));
}

int print_string(char *str)
{
	int count = 0;

	if (str == NULL)
		str = "(null)";
	while (*str)
	{
		count += write(1, str, 1);
		str++;
	}
	return (count);
}

int print_binary(unsigned int n)
{
	int count = 0;
	if (n > 1)
		count += print_binary(n >> 1);
	count += write(1, (n & 1) ? "1" : "0", 1);
	return (count);
}

int print_unsigned(unsigned int n)
{
	char buffer[11];
	int count = 0;

	if (n / 10)
		count += print_unsigned(n / 10);
	buffer[count] = (n % 10) + '0';
	count++;
	write(1, buffer, count);
	return (count);
}

int print_octal(unsigned int n)
{
	char buffer[11];
	int count = 0;

	if (n / 8)
		count += print_octal(n / 8);
	buffer[count] = (n % 8) + '0';
	count++;
	write(1, buffer, count);
	return (count);
}

int print_hex(unsigned int n, char format)
{
	char buffer[11];
	int count = 0;
	char *hex_chars = (format == 'x') ? "0123456789abcdef" : "0123456789ABCDEF";

	if (n / 16)
		count += print_hex(n / 16, format);
	buffer[count] = hex_chars[n % 16];
	count++;
	write(1, buffer, count);
	return (count);
}

