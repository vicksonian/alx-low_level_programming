#include "main.h"

/**
* _strcpy - copies a string from src to dest
* @dest: destination string
* @src: source string
*
* Return: pointer to dest
*/
char *_strcpy(char *dest, char *src)
{
char *cpyresult = dest;

if ((dest != NULL) && (src != NULL))
{
while (*src != '\0')
{
*dest++ = *src++;
}
*dest = '\0';
}
return (cpyresult);
}
