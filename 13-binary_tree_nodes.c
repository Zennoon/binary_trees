#include "binary_trees.h"

/**
 * is_leaf_node - Checks if a binary tree node is a leaf node or not
 * @node: Pointer to the node to check
 *
 * Description: A leaf node is a node that doesn't have any children
 * Return: 1 if the node is a leaf node, 0 otherwise (even if NULL is given)
 */
int is_leaf_node(const binary_tree_t *node)
{
	if (node && !node->left && !node->right)
		return (1);
	return (0);
}

/**
 * binary_tree_nodes - Returns number of intermediate nodes in a binary tree
 * @tree: Pointer to the root node of the tree whose leaves are counted
 *
 * Description: An intermediate node is a node that has children (isn't a leaf)
 * Return: Number of intermediate nodes in the tree
 */
size_t binary_tree_nodes(const binary_tree_t *tree)
{
	if (tree)
	{
		size_t left_nodes = binary_tree_nodes(tree->left);
		size_t right_nodes = binary_tree_nodes(tree->right);

		return (!is_leaf_node(tree) + left_nodes + right_nodes);
	}
	return (0);
}
