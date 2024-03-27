#include "main.h"

/**
 * this is a helper functions file.
*/

char print_string(va_list arg);
char print_character(va_list arg);
char print_percent(va_list arg);
int (*get_func(char format))(va_list arg);
