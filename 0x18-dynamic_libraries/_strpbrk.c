#include <stddef.h>
#include "main.h"

/**
 * _strpbrk - Searches a string for any of a set of bytes
 * @s: The string to search
 * @accept: The characters to search for
 *
 * Return: The pointer to the first occurrence in s of any character in accept,
 *         or NULL if no such character is found.
 */
char *_strpbrk(char *s, char *accept)
{
	while (*s != '\0' && _strchr(accept, *s) == NULL)
		s++;
	return (*s != '\0' ? s : NULL);
}
