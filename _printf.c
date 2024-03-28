#include "main.h"
#include <stdarg.h>
/**
 * _printf - Prints formatted output to stdout
 * @format: The format string
 * Return: The number of characters printed
 **/
int _printf(const char *format, ...)
{
	va_list args;
	int count = 0;
	const char *ptr = format;
	int (*func_p)(va_list) = 0;

	va_start(args, format);
	while (*ptr)
	{
		if (*ptr != '%')

		{					/* If the character is not a '%' */
			_putchar(*ptr); /* Write the character to the standard output */
			count++;		/* Increment the character count */
		}
		else
		{                       /* If the character is '%' */
			ptr++;              /* Move to the next char */
			if (*ptr == '\0')   /* If the next char is null terminator, return -1 */
				return (-1);
			/* Get the function pointer corresponding to the format specifier */
			func_p = get_func(*ptr);

			if (func_p != NULL) /* Check if the function pointer is valid */
				count += func_p(args); /* Call the function with variable arguments */
			else
			{
				_putchar('%');	/* Print '%' */
				_putchar(*ptr); /* Print the next character */
				count += 2;		/* Increment the count by 2 */
			}
		}
		ptr++;                 /* Move to the next character in the format str */
	}

	va_end(args); /* End */
	return (count);
}
