#include "main.h"

/**
 * _printf - A custom printf function that handles %c, %s, %d, %i, %b, %u, %o, %x, %X, and %%.
 * @format: The format string.
 * @...: The values to format and print.
 * 
 * Return: The number of characters printed.
 */
int _printf(const char *format, ...)
{
    va_list args_list;
    int count = 0;
    char buffer[1024]; // Local buffer
    int buffer_index = 0; // Index to track the buffer position

    va_start(args_list, format);

    while (*format) // Loop through each character in the format string
    {
        if (*format == '%') // Check for format specifier
        {
            format++; // Move to the next character
            if (*format == 'u') // Handle unsigned integer
            {
                unsigned int number = va_arg(args_list, unsigned int);
                char num_buffer[11]; // Enough for unsigned int
                int len = sprintf(num_buffer, "%u", number);
                for (int i = 0; i < len; i++) // Copy to main buffer
                {
                    if (buffer_index >= 1024) // Flush buffer if full
                    {
                        write(1, buffer, buffer_index);
                        count += buffer_index;
                        buffer_index = 0; // Reset buffer index
                    }
                    buffer[buffer_index++] = num_buffer[i];
                }
            }
            else if (*format == 'o')
            {
                unsigned int number = va_arg(args_list, unsigned int);
                char octal_buffer[22]; 
                int len = 0;
                if (number == 0)
                {
                    octal_buffer[len++] = '0';
                }
                else
                {
                    while (number > 0)
                    {
                        octal_buffer[len++] = (number % 8) + '0';
                        number /= 8;
                    }
                }
                
                for (int i = len - 1; i >= 0; i--)
                {
                    if (buffer_index >= 1024)
                    {
                        write(1, buffer, buffer_index);
                        count += buffer_index;
                        buffer_index = 0;
                    }
                    buffer[buffer_index++] = octal_buffer[i];
                }
            }
            else if (*format == 'x')
            {
                unsigned int number = va_arg(args_list, unsigned int);
                char hex_buffer[22];
                int len = 0;
                if (number == 0)
                {
                    hex_buffer[len++] = '0';
                }
                else
                {
                    while (number > 0)
                    {
                        int digit = number % 16;
                        hex_buffer[len++] = (digit < 10) ? (digit + '0') : (digit - 10 + 'a');
                        number /= 16;
                    }
                }
                
                for (int i = len - 1; i >= 0; i--) 
                {
                    if (buffer_index >= 1024)
                    {
                        write(1, buffer, buffer_index);
                        count += buffer_index;
                        buffer_index = 0; // Reset buffer index
                    }
                    buffer[buffer_index++] = hex_buffer[i];
                }
            }
            else if (*format == 'X') // Handle uppercase hexadecimal
            {
                unsigned int number = va_arg(args_list, unsigned int);
                char hex_buffer[22]; // Enough for hexadecimal representation
                int len = 0;
                if (number == 0) // Special case for zero
                {
                    hex_buffer[len++] = '0';
                }
                else
                {
                    while (number > 0) // Convert to hexadecimal
                    {
                        int digit = number % 16;
                        hex_buffer[len++] = (digit < 10) ? (digit + '0') : (digit - 10 + 'A');
                        number /= 16;
                    }
                }
                // Reverse the hexadecimal string
                for (int i = len - 1; i >= 0; i--) // Copy to main buffer
                {
                    if (buffer_index >= 1024) // Flush buffer if full
                    {
                        write(1, buffer, buffer_index);
                        count += buffer_index;
                        buffer_index = 0; // Reset buffer index
                    }
                    buffer[buffer_index++] = hex_buffer[i];
                }
            }
            else if (*format == '%') // Handle percent sign
            {
                if (buffer_index >= 1024) // Flush buffer if full
                {
                    write(1, buffer, buffer_index);
                    count += buffer_index;
                    buffer_index = 0; // Reset buffer index
                }
                buffer[buffer_index++] = '%'; // Add percent to buffer
            }
            else // Unknown format specifier
            {
                if (buffer_index >= 1024) // Flush buffer if full
                {
                    write(1, buffer, buffer_index);
                    count += buffer_index;
                    buffer_index = 0; // Reset buffer index
                }
                buffer[buffer_index++] = '%'; // Print '%'
                buffer[buffer_index++] = *format; // Print unknown specifier
            }
        }
        else
	{
            if (buffer_index >= 1024)
            {
                write(1, buffer, buffer_index);
                count += buffer_index;
                buffer_index = 0;
            }
            buffer[buffer_index++] = *format;
        }
        format++;
    }
    
    if (buffer_index > 0)
    {
        write(1, buffer, buffer_index);
        count += buffer_index;
    }

    va_end(args_list);
    return count;
}

