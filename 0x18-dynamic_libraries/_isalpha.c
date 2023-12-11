#include "main.h"

/**
 * _isalpha - Checks if a character is an alphabetic character
 * @c: The character to check
 *
 * Return: 1 if c is an alphabetic character, 0 otherwise.
 */
int _isalpha(int c)
{
	return (_islower(c) || _isupper(c));
}
