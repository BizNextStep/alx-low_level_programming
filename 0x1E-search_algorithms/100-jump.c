#include "search_algos.h"

/**
 * jump_search - Searches for a value in a sorted array of integers using
 *               the Jump search algorithm
 * @array: Pointer to the first element of the array to search in
 * @size: Number of elements in array
 * @value: Value to search for
 *
 * Return: The first index where value is located, or -1 if value is not
 *         present in array or if array is NULL
 */
int jump_search(int *array, size_t size, int value)
{
	size_t step = sqrt(size);
	size_t prev = 0;
	size_t next;

	if (array == NULL || size == 0)
		return (-1);

	if (array[step - 1] >= value) {
		while (prev < step && array[prev] < value) {
			printf("Value checked array[%ld] = [%d]\n", prev, array[prev]);
			prev++;
		}
		next = prev;
	} else {
		prev = step;
		while (prev < size && array[prev] < value) {
			printf("Value checked array[%ld] = [%d]\n", prev, array[prev]);
			prev++;
		}
		next = prev + step;
	}

	while (next < size && array[next] < value) {
		printf("Value checked array[%ld] = [%d]\n", next, array[next]);
		next++;
	}

	if (next < size && array[next] == value) {
		printf("Value found between indexes [%ld] and [%ld]\n", prev, next);
		printf("Value checked array[%ld] = [%d]\n", next, array[next]);
		return (next);
	}

	return (-1);
}
