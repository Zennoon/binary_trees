#include "binary_trees.h"

/**
 * is_leaf - Checks if a binary tree node is a leaf node or not
 * @node: Pointer to the node to check
 *
 * Description: A leaf node is a node that doesn't have any children
 * Return: 1 if the node is a leaf node, 0 otherwise (even if NULL is given)
 */
int is_leaf(const binary_tree_t *node)
{
	if (node && !node->left && !node->right)
		return (1);
	return (0);
}

/**
 * binary_tree_leaves - Returns the number of leaves in a binary tree
 * @tree: Pointer to the root node of the tree whose leaves are counted
 *
 * Return: Number of leaves in the tree
 */
size_t binary_tree_leaves(const binary_tree_t *tree)
{
	if (tree)
	{
		size_t left_leaves = binary_tree_leaves(tree->left);
		size_t right_leaves = binary_tree_leaves(tree->right);

		return (binary_tree_is_leaf(tree) + left_leaves + right_leaves);
	}
	return (0);
}
