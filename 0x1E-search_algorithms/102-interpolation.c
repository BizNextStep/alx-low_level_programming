#include <stdio.h>
#include <stdlib.h>
#include <math.h> /* Include math.h for sqrt function */
#include "search_algos.h"

/**
 * interpolation_search - Searches for a value in a sorted array of integers
 * using the Interpolation search algorithm
 * @array: Pointer to the first element of the array to search in
 * @size: Number of elements in array
 * @value: Value to search for
 *
 * Return: The index where value is located, or -1 if not found
 */
int interpolation_search(int *array, size_t size, int value)
{
    if (array == NULL || size == 0)
        return -1;

    return _interpolation_search(array, 0, size - 1, value);
}

/**
 * _interpolation_search - Recursive helper function for interpolation search
 * @array: Pointer to the first element of the array to search in
 * @low: Low index of the array
 * @high: High index of the array
 * @value: Value to search for
 *
 * Return: The index where value is located, or -1 if not found
 */
int _interpolation_search(int *array, size_t low, size_t high, int value)
{
	if (low > high)
		return (-1);

	size_t pos = low + (((double)(high - low) / (array[high] - array[low])) * (value - array[low]));

	if (pos >= size || array[pos] > value)
	{
		printf("Value checked array[%ld] is out of range\n", pos);
		return (-1);
	}

	if (array[pos] == value)
	{
		printf("Value checked array[%ld] = [%d]\n", pos, array[pos]);
		return pos;
	}

	printf("Value checked array[%ld] = [%d]\n", pos, array[pos]);

	if (array[pos] < value)
		return _interpolation_search(array, pos + 1, high, value);
	else
		return _interpolation_search(array, low, pos - 1, value);
}
