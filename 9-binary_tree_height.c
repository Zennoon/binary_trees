#include "binary_trees.h"

/**
 * max - Returns the maximum of two positive numbers
 * @n1: First number
 * @n2: Second number
 *
 * Return: The greatest of the two arguments
 */
size_t max(size_t n1, size_t n2)
{
	if (n1 >= n2)
		return (n1);
	return (n2);
}

/**
 * binary_tree_height - Returns the height of a binary tree
 * @tree: Pointer to the root node of the tree to measure
 *
 * Description: Height of a tree is the length of the longest path from a root
 * to a leaf.
 * Return: Height of the given binary tree
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	if (tree && (tree->left || tree->right))
	{
		size_t left_height = 1 + binary_tree_height(tree->left);
		size_t right_height = 1 + binary_tree_height(tree->right);

		return (max(left_height, right_height));
	}
	return (0);
}
