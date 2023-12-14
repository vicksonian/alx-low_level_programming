#include "main.h"

/**
* _strstr - locates a substring in a string
* @haystack: the string to search in
* @needle: the substring to search for
*
* Return: pointer to the beginning of the located substring, or NULL if not found
*/

char *_strstr(char *haystack, char *needle)
{
	char *h, *n;

	if (haystack == NULL || needle == NULL)
		return (NULL);
	for (; *haystack; haystack++)
	{

	for (h = haystack, n = needle; *h && *n && (*h == *n); h++, n++)
		;
	if (*n == '\0')
		return (haystack);
	}
	return (NULL);
}
