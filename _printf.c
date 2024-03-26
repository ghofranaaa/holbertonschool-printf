#include "main.h"
#include <stdarg.h>
#include <unistd.h>

int _printf(const char *format, ...)
{
	va_list args;			  // Declare a variable to hold the variable arguments
	int count = 0;			  // Initialize a counter for the number of characters printed
	const char *ptr = format; // Initialize a pointer to the format string

	va_start(args, format); // Start processing the variable arguments

	while (*ptr)
	{ // Loop
		if (*ptr != '%')
		{					  // If the character is not a '%'
			write(1, ptr, 1); // Write the character to the standard output
			count++;		  // counter
		}
		else
		{		   // If the character is a '%'
			ptr++; // Move to the next character
			if (*ptr == 'c')
			{								// If it is 'c'
				char c = va_arg(args, int); // get a character argument
				write(1, &c, 1);			// Write the character to the standard output
				count++;
			}
			else if (*ptr == 's')
			{									// If the conversion specifier is 's'
				char *s = va_arg(args, char *); // get a string argument
				while (*s)
				{					// Loop
					write(1, s, 1); // Write the character to the standard output
					s++;			// Move to the next character in the string
					count++;
				}
			}
			else if (*ptr == '%')
			{					  // If the conversion specifier is '%%'
				write(1, "%", 1); // Write a '%' character to the standard output
				count++;
			}
		}
		ptr++; // Move to the next character in the format string
	}

	va_end(args); // End

	return count; // Return the total number of characters printed
}
