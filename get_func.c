#include <stdarg.h>
#include "main.h"

/**
 * get_func - a function that contains the data base of the progran.
* Description: serves as a database for the printf function within the program.
* @format: The format specifier encountered.
* @arg: The va_list of arguments.]
* Return: Pointer to the printing function corresponding
* to the format specifier.
*/

int (*get_func(char format)(va_list arg))
{

{
		{'c', print_character},
		{'s', print_string},
		{'%', print_percent},
		{'i', print_integer},
		{'\0', NULL},
		};
}
