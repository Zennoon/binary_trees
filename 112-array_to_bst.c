#include "binary_trees.h"

/**
 * array_to_bst - Builds a binary search tree from an array of numbers
 * @array: Pointer to the first element of the array to be converted
 * @size: number of elements in the array
 *
 * Return: Pointer to the root node of the created binary search tree,
 * or NULL on failure
 */
bst_t *array_to_bst(int *array, size_t size)
{
	bst_t *root = NULL;
	size_t i;

	for (i = 0; i < size; i++)
	{
		if (!bst_insert(&root, array[i]))
			return (NULL);
	}
	return (root);
}
