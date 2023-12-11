#include "main.h"
#include <stddef.h>

/**
 * _strstr - Locates a substring within a string
 * @haystack: The string to search in
 * @needle: The substring to find
 *
 * Return: Pointer to the beginning of the located substring, or NULL if not found
 */
char *_strstr(char *haystack, char *needle)
{
	char *start;
	char *sub = needle;

	while (*haystack)

	{
		start = haystack;

		while (*haystack && *sub && *haystack == *sub)
		{
			haystack++;
			sub++;
		}

		if (!*sub)
			return (start);

		sub = needle;  /* Reset the pointer to the beginning of the substring */
		haystack = start + 1;
	}

	return (NULL);
}
