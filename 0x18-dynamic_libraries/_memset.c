#include "main.h"

/**
 * _memset - Fills the first n bytes of memory with a constant byte
 * @s: The memory area to fill
 * @b: The constant byte
 * @n: The number of bytes to fill
 *
 * Return: The pointer to the memory area.
 */
char *_memset(char *s, char b, unsigned int n)
{
	unsigned int i = 0;

	while (i < n)
	
	{
		s[i] = b;
		i++;
	}
	return (s);
}
