#include "main.h"

/**
 * _atoi - Converts a string to an integer
 * @s: The string to convert
 *
 * Return: The converted integer.
 */
int _atoi(char *s)
{
	int result = 0;
	int i = 0;

	while (s[i] != '\0')

	{
		result = result * 10 + (s[i] - '0');
		i++;
	}
	return (result);
}
