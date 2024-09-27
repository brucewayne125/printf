#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>

int _printf(const char *format, ...);
int print_char(char c);
int print_string(char *str);
int print_binary(unsigned int n);
int print_unsigned(unsigned int n);
int print_octal(unsigned int n);
int print_hex(unsigned int n, char format);

#endif /* MAIN_H */
