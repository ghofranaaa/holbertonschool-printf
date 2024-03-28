#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <stdio.h>
#include <string.h>

/* Function prototypes */
int _printf(const char *format, ...);
int print_string(va_list arg);
int print_character(va_list arg);
int print_percent(va_list arg);
int (*get_func(char format))(va_list);
int _putchar(char c);
int Jump_to_secand_specifier(char specifier, va_list args);

/**
 * struct fmt - struct declaration.
 * @str: format specifier.
 * @p: pointer to function.
 */
typedef struct fmt
{
	char str;
	int (*p)(va_list);
} f;


#endif /* MAIN_H */
