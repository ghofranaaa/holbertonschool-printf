#include "main.h"
#include <stdarg.h>
#include <unistd.h>

/**
 * _printf - Prints formatted output to stdout
 * @format: The format string
 *
 * Return: The number of characters printed
 */
int _printf(const char *format, ...)
{
	va_list args;               /* Declare a var to hold the var arguments */
	int count = 0;              /* Init a counter */
	const char *ptr = format;   /* Initialize a pointer to the format string */
	va_start(args, format);     /* Start processing the variable arguments */
	while (*ptr)
	{
		if (*ptr != '%')
		{                       /* If the character is not a '%' */
			_putchar(*ptr);     /* Writeee the character to the standard output */
			count++;            /* Increment the character count */
		}
		else
		{                       /* If the character is a '%' */
			ptr++;              /* Move to the next character */
			if (*ptr == '\0')   /* If the next char is null terminator, return -1 */
				return (-1);

			switch (*ptr)       /* Switch stat to handle diff format specifiers */
			{
			case 'c':           /* If the specifier is 'c' */
				count += print_character(args);
				break;
			case 's':           /* If the specifier is 's' */
				count += print_string(args);
				break;
			case '%':           /* If the specifier is '%' */
				_putchar('%');
				count++;
				break;
			default:
				_putchar('%');  /* Print '%' */
				_putchar(*ptr); /* Print the next character */
				count += 2;     /* Increment the count by 2 */
				break;
			}
		}
		ptr++;                 /* Move to the next character in the format string */
	}
	va_end(args);             /* End */
	return (count);           /* Return the total number of characters printed */
}
