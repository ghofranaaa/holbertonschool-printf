
![Logo](https://blog.holbertonschool.com/wp-content/uploads/2021/05/cropped-Fichier-16.png)



# C - printf

This project provides a customized version of the printf function in C. It supports basic formatting specifiers such as %d, %f, %s, etc., and handles variadic arguments for flexibility.
## Authors

- [@OussemaTurki0](https://github.com/OussemaTurki0)
- [@ghofranaaa](https://github.com/ghofranaaa)


## Project Requirements

Compilation: All files will be compiled on Ubuntu 20.04 LTS using gcc, with the options -Wall -Werror -Wextra -pedantic -std=gnu89.

Newline: All files should end with a new line.

README.md: A README.md file is mandatory at the root of the project folder.

Coding Style: The code should follow the Betty style, checked using betty-style.pl and betty-doc.pl.

Global Variables: No use of global variables.

Functions per File: No more than 5 functions are allowed per file.

Prototypes: All function prototypes should be included in a header file named main.h.

Header Files: All header files should be include guarded.


## API Reference

#### Files used :



| File Name :         | Description :                |
| :------------------ | :------------------------- |
| `main.c`            | Contains the main function to test the _printf function with various format specifiers. |
| `a_printf.c`        | Contains the implementation of the _printf function. |
| `_putchar.c`        | Contains the _putchar function used by _printf to print characters. |
| `get_func.c`        | Contains the get_func function used by _printf to select the appropriate printing function for each format specifier. |
| `main.h`            | Declarations |
| `print_functions.c` | Contains the printing functions for %c, %s, and %% conversions. |

## Supported Conversion Specifiers:

|     Specifiers :     |         Description :        |
| ------------- | --------------------- |
| %c | Prints a single character.|
| %s | Prints a null-terminated string.|
| %% | Prints a percent sign.|
| %d | Prints a signed decimal integer.|
| %i | Prints a signed decimal integer.|



## Flowchart

![Logo](https://i.postimg.cc/zf2L0mJ7/untitled.png)
