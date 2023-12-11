#include <stddef.h>
#include "main.h"

/**
 * _strspn - Gets the length of a prefix substring
 * @s: The string to check
 * @accept: The characters to include in the prefix
 *
 * Return: The number of bytes in the initial segment of s which consist
 *         only of bytes from accept.
 */
unsigned int _strspn(char *s, char *accept)
{
	unsigned int count = 0;

	while (*s != '\0' && *accept != '\0' && _strchr(accept, *s) != NULL)
	{
		count++;
		s++;
	}
	return (count);
}
