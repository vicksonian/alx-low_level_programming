#include "main.h"

/**
* _strpbrk - searches a string for any set of bytes
* @s: input string
* @accept: set of bytes to search for
*
* Return: pointer to the first occurrence in s of any byte in accept,
*         or NULL if no such byte is found
*/

char *_strpbrk(char *s, char *accept)
{
	int i, k, pos, Z = 0;

	for (i = 0; s[i] != '\0'; i++)
		;

	pos = i;

	for (i = 0; accept[i] != '\0'; i++)
	{
		for (k = 0; s[k] != '\0'; k++)
		{
			if (accept[i] == s[k])
			{
				if (k <= pos)
				{
					pos = k;
					Z = 1;
				}
			}
		}
	}
	if (Z == 1)
	{
		return (&s[pos]);
	}
	else
	{
		return (0);
	}
}
