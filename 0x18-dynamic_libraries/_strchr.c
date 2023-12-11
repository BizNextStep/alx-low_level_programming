#include <stddef.h>
#include "main.h"

/**
 * _strchr - Locates the first occurrence of a character in a string
 * @s: The string to search
 * @c: The character to locate
 *
 * Return: The pointer to the first occurrence of c in s, or NULL if not found.
 */
char *_strchr(char *s, char c)
{
	while (*s != '\0' && *s != c)
		s++;
	return (*s == c ? s : NULL);
}
