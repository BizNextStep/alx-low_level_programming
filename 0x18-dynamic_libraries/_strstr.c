#include "main.h"
#include <stddef.h>

/**
 * _strstr - Locates a substring
 * @haystack: The string to search
 * @needle: The substring to locate
 *
 * Return: The pointer to the beginning of the located substring,
 *         or NULL if not found.
 */
char *_strstr(char *haystack, char *needle)
{
	while (*haystack)

	{
		char *start = haystack;
		char *sub = needle;

		while (*haystack)

		{
			start = haystack;

		while (*haystack && *substr && *haystack == *substr)

		{
			haystack++;
			substr++;
		}

		if (*substr)
			return (start);

		substr = needle; /* Reset the pointer to the beginning of the substring */
		haystack = start + 1;
	}

	return (NULL);
}
