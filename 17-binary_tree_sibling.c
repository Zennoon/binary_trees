#include "binary_trees.h"

/**
 * binary_tree_sibling - Retrieves the sibling of a given node, if it exists
 * @node: Pointer to the node whose sibling is returned
 *
 * Return: Pointer to the sibling, or NULL if fail
 */
binary_tree_t *binary_tree_sibling(binary_tree_t *node)
{
	binary_tree_t *sibling = NULL;

	if (node && node->parent)
	{
		if (node == node->parent->left)
			sibling = node->parent->right;
		else
			sibling = node->parent->left;
	}
	return (sibling);
}
