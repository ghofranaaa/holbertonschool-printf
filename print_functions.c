#include "main.h"

/**
 * print_string - printing string.
 * @args: va_list type.
 * Return: integer, otherwise NULL.
 */

int print_string(va_list args)
{
	char *string;
	int i;
	int count = 0;

	string = va_arg(args, char *);

	if (string == NULL)
		string = "(null)";

	for (i = 0; string[i] != '\0'; i++)
	{
		_putchar(string[i]);
		count++;
	}
	return (count);
}

/**
 * print_character - printing character.
 * @args: va_list type.
 * Return: 1 on success, otherwise NULL.
 */

int print_character(va_list args)
{
	_putchar(va_arg(args, int));
	return (1);
}

/**
 * print_percent - printing percent character.
 * @args: va_list type.
 * Return: 1 on success, otherwise NULL.
 */

int print_percent(va_list args)
{
	(void)args;
	_putchar('%');
	return (1);
}
