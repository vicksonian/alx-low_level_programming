#include "main.h"

/**
* _strchr - locates a character in a string
* @s: input string
* @c: character to locate
*
* Return: pointer to the first occurrence of c in s, or NULL if not found */
char *_strchr(char *s, char c)
{
	char *p = s;

	for (; *p != '\0'; p++)
	{
		if (*p == c)
			return (p);
	}
	if (*p == c)
		return (p);
	return (0);
}
