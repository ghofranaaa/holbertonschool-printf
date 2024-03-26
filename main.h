#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <stdio.h>
#include <string.h>

/* Function prototypes */

int _printf(const char *format, ...);
char print_string(va_list arg);
char print_character(va_list arg);
char print_percent(va_list arg);
int print_integer(va_list arg);
int (*get_func(char format)(va_list arg));

/**
 * struct fmt - struct declaration.
 * @str: format specifier.
 * @p: pointer to function.
*/
typedef struct fmt
{
	int str;
	int (*p)(va_list);
} f;


#endif /* MAIN_H */

