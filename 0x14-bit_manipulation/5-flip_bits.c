/**
 * flip_bits - Count the number of bits that need to be flipped
 * to get from one number to another
* @n: The first number
* @m: The second number
* Return: The number of bits to flip to get from n to m
*/

#include "main.h"

unsigned int flip_bits(unsigned long int n, unsigned long int m)
{
unsigned long int xor_result = n ^ m;
unsigned int count = 0;

while (xor_result > 0)
{
count += xor_result & 1;
xor_result >>= 1;
}

return (count);
}
