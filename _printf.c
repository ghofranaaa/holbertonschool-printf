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
    int count = 0;          /* Init a counter for the number of char printed */
    const char *ptr = format;   /* Init a pointer to the format str */
    int (*func_p)(va_list) = 0;

    if (format == NULL)     /* Check if the format str is NULL */
        return (-1);

    va_start(args, format); /* Start the var argument list */

    while (*ptr)            /* Loop */
    {
        if (*ptr != '%')    /* Check if the current character is not '%' */
        {
            _putchar(*ptr); /* Print the char to stdout */
            count++;
        }
        else                /* If the current char is '%' */
        {
            ptr++;          /* Move to the next char */
            if (*ptr == '\0')   /* Check if the next char is NULL */
                return (-1);    /* Return -1 if the next char is NULL */

            func_p = get_func(*ptr);    /* Get the printing function for the specifier */

            if (func_p != NULL)         /* If a valid printing function is found */
                count += func_p(args);  /* Call the printing function and update the count */
            else                        /* If no valid printing function is found */
            {
                _putchar('%');          /* Print '%' */
                _putchar(*ptr);         /* Print the specifier character */
                count += 2;             /* Increment the count by 2 (for '%' and the specifier character) */
            }

        }
        ptr++;
    }

    va_end(args);
    return (count); /* Return the total number of characters printed */
}
