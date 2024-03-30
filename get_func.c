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

int (*get_func(char format))(va_list args)
{
	f fu[] = {
		{'c', print_character}, /* Char specifier */
		{'s', print_string},    /* Str specifier */
		{'%', print_percent},   /* Percent specifier */
		{'\0', NULL},           /* Null terminator to indicate end of array */
	};

	int i; /* Declare an int variable i */

	for (i = 0; fu[i].fs != '\0'; i++)
	{
		if (fu[i].fs == format)
		{
			return (fu[i].p);
		}
	}

	return (NULL); /* If no match is found, return NULL */
}
