#include "main.h"
#include <stdio.h>

/**
 * get_bit - gets the value of a bit at a given index
 * @n: unsigned long integer
 * @index: index of the bit to retrieve, starting from 0
 *
 * Return: value of the bit at index or -1 if an error occurred
 */
int get_bit(unsigned long int n, unsigned int index)
{
	if (index >= sizeof(unsigned long int) * 8)
	{
		return (-1); /* Error: index out of range */
	}

	return ((n >> index) & 1);
}

int main(void)

{
	unsigned long int number = 12345;
	unsigned int bit_index = 3;
	int bit_value = get_bit(number, bit_index);
	printf("The value of bit %u in number %lu is %d\n",
			bit_index, number, bit_value);

	return (0);
}
