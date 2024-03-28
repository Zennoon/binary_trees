#include "binary_trees.h"

/**
 * binary_tree_is_leaf - Checks if a binary tree node is a leaf node or not
 * @node: Pointer to the node to check
 *
 * Description: A leaf node is a node that doesn't have any children
 * Return: 1 if the node is a leaf node, 0 otherwise (even if NULL is given)
 */
int binary_tree_is_leaf(const binary_tree_t *node)
{
	if (node && !node->left && !node->right)
		return (1);
	return (0);
}
