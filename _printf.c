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
	const char *ptr = format;   /* Init a pointer to the format str */
	va_start(args, format);     /* Start process the var arguments */
	while (*ptr)
	{
		if (*ptr != '%')
		{                       /* If the character is not '%' */
			_putchar(*ptr);     /* Write the char to the standard output */
			count++;
		}
		else
		{                       /* If the character is '%' */
			ptr++;              /* Move to the next char */
			if (*ptr == '\0')   /* If the next char is null terminator, return -1 */
				return (-1);

			switch (*ptr)       /* Switch stat to handle diff format specif */
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
				_putchar(*ptr); /* Print the next char */
				count += 2;     /* Increment the count by 2 */
				break;
			}
		}
		ptr++;                 /* Move to the next character in the format str */
	}
	va_end(args);             /* End */
	return (count);           /* Return the total number of characters printed */
}
