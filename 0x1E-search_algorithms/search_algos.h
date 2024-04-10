#ifndef SEARCH_ALGOS_H
#define SEARCH_ALGOS_H

#include <stdio.h>
#include <math.h> /* Include math.h for sqrt function */

/**
 * struct search_node_s - Node structure for search algorithms
 *
 * @value: The value to search for
 * @index: The index of the node in the array
 * @next: Pointer to the next node in the array
 */
typedef struct search_node_s
{
    int value;
    size_t index;
    struct search_node_s *next;
} search_node_t;

/**
 * linear_search - Searches for a value in an array of integers
 *                  using the Linear search algorithm
 * @array: Pointer to the first element of the array to search in
 * @size: Number of elements in array
 * @value: Value to search for
 *
 * Return: The first index where value is located, or -1 if value is not
 *         present in array or if array is NULL
 */
int linear_search(int *array, size_t size, int value);

int binary_search(search_node_t *array, size_t size, int value);
int jump_search(search_node_t *array, size_t size, int value);
int interpolation_search(search_node_t *array, size_t size, int value);

#endif /* SEARCH_ALGOS_H */
