#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <stdio.h>
#include <string.h>

/* Function prototypes */
int _printf(const char *format, ...);
int print_string(va_list args);
int print_character(va_list args);
int print_percent(va_list args);
int (*get_func(char format))(va_list);
int _putchar(char c);
int print_integer(va_list args);
int print_number(int n);

/**
 * struct fmt - struct declaration.
 * @fs: format specifier.
 * @p: pointer to function.
 */
typedef struct fmt
{
char fs;
int (*p)(va_list);
} f;

#endif /* MAIN_H */
