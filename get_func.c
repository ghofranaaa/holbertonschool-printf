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
		{'c', print_character}, /* Character specifier */
		{'s', print_string},    /* String specifier */
		{'%', print_percent},   /* Percent specifier */
		{NULL, NULL},           /* Null terminator to indicate end of array */
		{'\0', NULL},           /* Null terminator to indicate end of array */
		

	};

	int i; /* Declare an integer variable i */

	for (i = 0; fu[i].str != '\0'; i++) /* Loop through the array until null terminator is reached */
	{
		if (fu[i].str == format) /* Check if the current format specifier matches the input format */
		{
			return (fu[i].p); /* Return the corresponding function pointer */
		}
	}

	return (NULL); /* If no match is found, return NULL */

	return (NULL);
}
