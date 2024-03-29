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

/**
 * print_integer - Prints an integer
 * @args: The va_list of arguments
 *
 * Return: The number of characters printed
 */
int print_integer(va_list args)
{
    int num = va_arg(args, int);
    int count = 0;
    /* Handle negative numbers */
    if (num < 0)
    {
        _putchar('-');
        count++;
        num = -num;
    }
    /* Print each digit */
    count += print_number(num);
    return (count);
}

/**
 * print_number - Prints a number
 * @n: The number to print
 *
 * Return: The number of digits printed
 */
int print_number(int n)
{
    int count = 0;
    /* Base case: If n is 0, print 0 */
    if (n == 0)
    {
        _putchar('0');
        return (1);
    }
    /* Recursively print digits */
    if (n / 10)
        count += print_number(n / 10);
    _putchar(n % 10 + '0');
    return (count + 1);
}
