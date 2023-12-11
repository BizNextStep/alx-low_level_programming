#include "main.h"

/**
 * _strncpy - Copies a specified number of characters from source to destination
 * @dest: The destination string
 * @src: The source string
 * @n: The number of characters to copy
 *
 * Return: The pointer to dest.
 */
char *_strncpy(char *dest, char *src, int n)
{
	int i;
	for (i = 0; i < n && src[i] != '\0'; i++)
	{
		dest[i] = src[i];
	}
	
	/* If n is greater than the length of src, pad dest with null bytes */
	for (; i < n; i++)
	{
		dest[i] = '\0';
	}

	return (dest);
}
