#include "binary_trees.h"

/**
 * bst_search - Searches for and returns a node with a given value from a BST
 * @tree: Pointer to the root node of the BST to search inside
 * @value: The value to search
 *
 * Return: The node holding the desired value, or NULL if not found
 */
bst_t *bst_search(const bst_t *tree, int value)
{
	bst_t *node = (bst_t *) tree;

	while (node)
	{
		if (node->n == value)
			break;
		else if (node->n > value)
			node = node->left;
		else
			node = node->right;
	}
	return (node);
}
