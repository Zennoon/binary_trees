#include "binary_trees.h"

/**
 * getmax - Returns the maximum of two positive numbers
 * @n1: First number
 * @n2: Second number
 *
 * Return: The greatest of the two arguments
 */
size_t getmax(size_t n1, size_t n2)
{
	if (n1 >= n2)
		return (n1);
	return (n2);
}

/**
 * get_binary_tree_height - Returns the height of a binary tree
 * @tree: Pointer to the root node of the tree to measure
 *
 * Description: Height of a tree is the length of the longest path from a root
 * to a leaf.
 * Return: Height of the given binary tree
 */
size_t get_binary_tree_height(const binary_tree_t *tree)
{
	if (tree && (tree->left || tree->right))
	{
		size_t left_height = 1 + get_binary_tree_height(tree->left);
		size_t right_height = 1 + get_binary_tree_height(tree->right);

		return (getmax(left_height, right_height));
	}
	return (0);
}

/**
 * is_leafnode - Checks if a binary tree node is a leaf node or not
 * @node: Pointer to the node to check
 *
 * Description: A leaf node is a node that doesn't have any children
 * Return: 1 if the node is a leaf node, 0 otherwise (even if NULL is given)
 */
int is_leafnode(const binary_tree_t *node)
{
	if (node && !node->left && !node->right)
		return (1);
	return (0);
}

/**
 * get_binary_tree_leaves - Returns the number of leaves in a binary tree
 * @tree: Pointer to the root node of the tree whose leaves are counted
 *
 * Return: Number of leaves in the tree
 */
size_t get_binary_tree_leaves(const binary_tree_t *tree)
{
	if (tree)
	{
		size_t left_leaves = get_binary_tree_leaves(tree->left);
		size_t right_leaves = get_binary_tree_leaves(tree->right);

		return (is_leafnode(tree) + left_leaves + right_leaves);
	}
	return (0);
}

/**
 * binary_tree_is_perfect - Checks if a given tree is perfect
 * @tree: Pointer to the root node of the tree to check
 *
 * Description: A tree is perfect if all the levels are filled.
 * Return: 1 if the tree is perfect, 0 otherwise
 */
int binary_tree_is_perfect(const binary_tree_t *tree)
{
	if (tree)
	{
		size_t checker = 1;
		size_t l = get_binary_tree_leaves(tree);
		size_t h = get_binary_tree_height(tree);

		while (h)
		{
			checker *= 2;
			h -= 1;
		}
		return (checker == l);
	}
	return (0);
}
