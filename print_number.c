#include "main.h"

/**
 * print_number - prints an integer as a string
 * @n: the integer to print
 * @count: pointer to the count of characters printed
 */
void print_number(int n, int *count)
{
	if (n < 0)
	{
		*count += write(1, "-", 1);
		n = -n;
	}
	if (n / 10)
	{
		print_number(n / 10, count);
	}
	_printf("%c", "0"[n % 10]);
}

/**
 * handle_integer - handles the %d and %i format specifiers
 * @args: the argument list
 * @count: pointer to the count of characters printed
 */
void handle_integer(va_list args, int *count)
{
	int num;

	num = va_arg(args, int);
	print_number(num, count);
}

/**
 * _printf - produces output according to a format
 * @format: format string
 *
 * Return: the number of characters printed (excluding the null byte)
 */
