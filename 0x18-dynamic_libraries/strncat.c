#include "main.h"
/**
* _strncat - concatenates n characters from src to dest
* @dest: destination string
* @src: source string
* @n: number of characters to concatenate
*
* Return: pointer to the resulting string dest
*/

char *_strncat(char *dest, char *src, int n)
{
	int x, y;

	for (x = 0; dest[x] != '\0'; x++)
		;
	for (y = 0; src[y] != '\0' && y < n; y++)
	{
		dest[x + y] = src[y];
	}
	dest[x + y] = '\0';
	return (dest);
}

