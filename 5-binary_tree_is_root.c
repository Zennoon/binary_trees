#include "binary_trees.h"

/**
 * binary_tree_is_root - Checks if a given node is the root of a tree or not
 * @node: Pointer to the node to check
 *
 * Description: The root of a tree is the only node in a tree without a parent
 * Return: 1 if the node is a root, 0 otherwise (even if NULL is given)
 */
int binary_tree_is_root(const binary_tree_t *node)
{
	if (node && !node->parent)
		return (1);
	return (0);
}
