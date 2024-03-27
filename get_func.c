#include <stdarg.h>
#include "main.h"

/**
 * get_func - A function that contains the database of the program.
 * @format: The format specifier encountered.
 *
 * Description: This function serves as a database for the printf
 * function within the program. It returns a pointer to the printing
 * function corresponding to the format specifier.
 *
 * Return: Pointer to the printing function corresponding to the
 * format specifier.
 */

int (*get_func(char format))(va_list arg)
{
	f fu[] = {
		{'c', print_character},
		{'s', print_string},
		{'%', print_percent},
		{'\0', NULL},
	};

	int i;

	for (i = 0; fu[i].str != '\0'; i++)
	{
		if (fu[i].str == format)
		{
			return (fu[i].p);
		}
	}

	return (NULL);
}
