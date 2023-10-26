#include "main.h"

/**
* print_binary - Print the binary representation of a number
* @n: The number to be converted and printed
*/

void print_binary(unsigned long int n)
{
if (n > 1)
print_binary(n >> 1);
_putchar((n & 1) + '0');
}
