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

    va_start(args, format);

    while (*ptr)
    {
        if (*ptr != '%')
        {
            write(1, ptr, 1); // Print the character
            count++;
        }
        else
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
