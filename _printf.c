#include "main.h"
#include <stdarg.h>

/**
 * _printf - Prints formatted output to stdout
 * @format: The format string
 *
 * Return: The number of characters printed
 */
int _printf(const char *format, ...)
{
	va_list args;
	int count = 0;

	if (format == NULL)
		return (-1);

	va_start(args, format);
	count = handle_format(format, args);
	va_end(args);

	return (count);
}

/**
 * handle_format - Handles the format string and calls the appropriate
 *                 printing functions for each specifier
 * @format: The format string
 * @args: The va_list of arguments
 *
 * Return: The number of characters printed
 */
int handle_format(const char *format, va_list args)
{
	int count = 0;
	const char *ptr = format;
	int (*func_p)(va_list) = 0;

	while (*ptr)
	{
		if (*ptr != '%')
		{
			_putchar(*ptr);
			count++;
		}
		else
		{
			ptr++;
			if (*ptr == '\0')
				return (-1);

			func_p = get_func(*ptr);

			if (func_p != NULL)
				count += func_p(args);
			else
			{
				if (*ptr == 's')
					count += print_string(args);
				else if (*ptr == 'c')
					count += print_character(args);
				else if (*ptr == '%')
					count += print_percent(args);
				else
				{
					_putchar('%');
					_putchar(*ptr);
					count += 2;
				}
			}
		}
		ptr++;
	}

	return (count);
}
