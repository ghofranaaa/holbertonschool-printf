#include "main.h"

/**
 * print_string - printing string.
 * @arg: va_list type.
 * Return: integer, otherwise NULL.
 */

int print_string(va_list arg)
{
	char *string;
	int i;

	string = va_arg(arg, char *);

	if (string == NULL)
		string = "(null)";

	for (i = 0; string[i] != '\0'; i++)
	{
		_putchar(string[i]);
	}
	return (i);
}

/**
 * print_character - printing character.
 * @arg: va_list type.
 * Return: 1 on success, otherwise NULL.
 */

int print_character(va_list arg)
{
	_putchar(va_arg(arg, int));
	return (1);
}

/**
 * print_percent - printing character.
 * @arg: va_list type.
 * Return: 1 on success, otherwise NULL.
 */

int print_percent(va_list arg)
{
	int percent __attribute__((unused)) = va_arg(arg, int);
	_putchar('%');
	return (1);
}
