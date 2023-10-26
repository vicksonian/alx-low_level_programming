/**
* get_endianness - Check the endianness of the machine
*
* Return: 0 if big endian, 1 if little endian
*/

#include "main.h"

int get_endianness(void)
{
	unsigned int num = 1;
	char *endian_check = (char *)&num;

if (*endian_check == 1)
	return (1);
else
	return (0);
}
