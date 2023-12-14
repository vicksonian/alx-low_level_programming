#include "main.h"

/**
* _abs - computes the absolute value of an integer
* @n: the integer to compute the absolute value of
*
* Return: absolute value of n
*/

int _abs(int n)
{
	if (n >= 0)
	{
		return (n);
	}
	if (n < 0)
	{
		return ((n * -1));
	}
	return (0);
}
