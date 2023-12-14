#include "main.h"
#include <stdio.h>

/**
* _puts - prints a string to stdout
* @s: input string
*/

void _puts(char *str)
{
	while (*str != '\0')
	{
		_putchar(*str);
		str++;
	}
	_putchar('\n');
}
