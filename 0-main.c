#include "main.h"
#include <stdio.h>

/**
 * main - entry point of progran
 * Description: testing the printf function
 * Return: void
*/

int main(void)
{
	int len;

	printf("Let's try to printf a simple sentence.\n");
	len = _printf("Let's try to printf a simple sentence.\n");
	printf("Length:[%d, %i]\n", len, len);

	printf("\n");

	printf("Testing character specifier:\n");
	len = _printf("Character: %c\n", 'A');
	printf("Length:[%d, %i]\n", len, len);

	printf("\n");

	printf("Testing string specifier:\n");
	len = _printf("String: %s\n", "Hello, world!");
	printf("Length:[%d, %i]\n", len, len);

	printf("\n");

	printf("Testing percent specifier:\n");
	len = _printf("Percent: %%\n");
	printf("Length:[%d, %i]\n", len, len);

	return (0);
}
