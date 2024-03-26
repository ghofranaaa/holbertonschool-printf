#include "main.h"
#include <stdarg.h>
#include <unistd.h>

int _printf(const char *format, ...)
{
    va_list args;
//va_list args : Declares a variable args of type va_list, which is used to hold the variable arguments passed to the function.
    int count = 0;
//int count = 0 :Declares and initializes an integer variable count to 0
    const char *ptr = format;
//const char *ptr = format: Declares a pointer ptr and initializes it to point to the beginning of the format string.
    va_start(args, format);
//va_start(args, format);: Initializes the args variable to start processing the variable arguments. The format argument is passed to va_start to determine the location of the first variable argument.
    while (*ptr)
//loop intil it reashes 0
    {
        if (*ptr != '%')
//if (*ptr != '%'): Checks if the current character is not a % character
        {
            write(1, ptr, 1); // Print the character
            count++;
        }
        else
//else: Starts the else block, which means the current character is a %
        {
            ptr++; // Move to the next character after '%'
            if (*ptr == 'c')
            {
                // Handle %c
                char c = va_arg(args, int);
                write(1, &c, 1);
                count++;
            }
            else if (*ptr == 's')
            {
                // Handle %s
                char *s = va_arg(args, char *);
                while (*s)
                {
                    write(1, s, 1);
                    s++;
                    count++;
                }
            }
            else if (*ptr == '%')
            {
                // Handle %%
                write(1, "%", 1);
                count++;
            }
        }
        ptr++;
    }

    va_end(args);

    return count;
}
