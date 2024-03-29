#include "main.h"
#include <stdarg.h>

/**
 * _printf - Prints formatted output to stdout
 * @format: The format str
 *
 * Return: The number of char printed
 */
int _printf(const char *format, ...)
{
    va_list args;                                    /* Var arguments list */
    int count = 0;                                   /* Init counter for chars printed */
    const char *ptr = format;                        /* Init pointer to format str */
    int (*func_p)(va_list) = NULL;                   /* Init function pointer to NULL */

    if (format == NULL)                              /* Check if format str is NULL */
        return (-1);

    va_start(args, format);                          /* Start var arguments list */

    while (*ptr)                                     /* Loop through format str */
    {
        if (*ptr != '%')                             /* If current char is not '%' */
        {
            _putchar(*ptr);                          /* Print the char */
            count++;                                 /* Increment char count */
        }
        else                                         /* If current char is '%' */
        {
            ptr++;                                   /* Move to next char */
            if (*ptr == '\0')                        /* If next char is NULL */
                return (-1);                         /* Return -1 */

            func_p = get_func(*ptr);                 /* Get function pointer for specifier */

            if (func_p != NULL)                      /* If valid function pointer found */
                count += func_p(args);               /* Call function and update count */
            else                                     /* If no valid function pointer found */
            {
                if (*ptr == 's')                     /* If specifier is 's' */
                    count += print_string(args);     /* Call print_string and update count */
                else if (*ptr == 'c')                /* If specifier is 'c' */
                    count += print_character(args);  /* Call print_character and update count */
                else if (*ptr == '%')                /* If specifier is '%' */
                    count += print_percent(args);    /* Call print_percent and update count */
                else if (*ptr == 'd' || *ptr == 'i') /* If specifier is 'd' or 'i' */
                    count += print_integer(args);    /* Call print_integer and update count */
                else                                 /* If unknown specifier */
                {
                    _putchar('%');                   /* Print '%' */
                    _putchar(*ptr);                  /* Print specifier char */
                    count += 2;                      /* Increment count by 2 */
                }
            }
        }
        ptr++;                                       /* Move to next char in format str */
    }

    va_end(args);                                    /* End */
    return (count);
}
