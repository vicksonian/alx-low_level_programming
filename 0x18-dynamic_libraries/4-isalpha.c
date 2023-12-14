#include "main.h"

/**
* _isalpha - checks if a character is alphabetic
* @c: the character to check
*
* Return: 1 if c is alphabetic, 0 otherwise
*/

int _isalpha(int c)
{
	if ('A' <= c && c <= 'Z')
	{
		return (1);
	}
	if ('a' <= c && c <= 'z')
	{
		return (1);
	}
	else
	{
		return (0);
	}
}
