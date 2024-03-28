#include "binary_trees.h"

/**
 * binary_tree_uncle - Retrieves the uncle of a given node, if it exists
 * @node: Pointer to the node whose uncle is returned
 *
 * Return: Pointer to the uncle, or NULL if fail
 */
binary_tree_t *binary_tree_uncle(binary_tree_t *node)
{
	binary_tree_t *uncle = NULL;

	if (node && node->parent && node->parent->parent)
	{
		if (node->parent == node->parent->parent->left)
			uncle = node->parent->parent->right;
		else
			uncle = node->parent->parent->left;
	}
	return (uncle);
}
