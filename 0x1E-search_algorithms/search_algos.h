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

int linear_search(search_node_t *array, size_t size, int value);
int binary_search(search_node_t *array, size_t size, int value);
int jump_search(search_node_t *array, size_t size, int value);
int interpolation_search(search_node_t *array, size_t size, int value);

#endif /* SEARCH_ALGOS_H */
