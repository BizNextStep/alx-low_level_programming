#include "main.h"

/**
 * _strcat - Concatenates two strings
 * @dest: The destination string
 * @src: The source string
 *
 * Return: The pointer to dest.
 */
char *_strcat(char *dest, char *src)
{
	int dest_len = _strlen(dest);
	int i = 0;

	while (src[i] != '\0')

	{
		dest[dest_len + i] = src[i];
		i++;
	}
	dest[dest_len + i] = '\0';  /* Don't forget to add the end marker! */
	return (dest);
}
