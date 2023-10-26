/**
* clear_bit - Set the value of a bit to 0 at a given index
* @n: A pointer to the number to modify
* @index: The index of the bit to set to 0, starting from 0
* Return: 1 if it worked, or -1 if an error occurred
*/

#include "main.h"

int clear_bit(unsigned long int *n, unsigned int index)
{
if (index >= (sizeof(*n) * 8))
return (-1);

*n = *n & ~(1 << index);
return (1);
}
