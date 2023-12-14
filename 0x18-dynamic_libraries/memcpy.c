#include "main.h"
/**
* _memcpy - copies memory area from src to dest
* @dest: destination memory area
* @src: source memory area
* @n: number of bytes to copy
*
* Return: pointer to dest
*/
char *_memcpy(char *dest, char *src, unsigned int n)
{
	char *p = dest;

	while (n--)
	{
		*p++ = *src++;
	}
	return (dest);
}
