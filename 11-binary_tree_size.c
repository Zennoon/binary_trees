#include "binary_trees.h"

/**
 * binary_tree_size - Returns the size (number of nodes) of a tree
 * @tree: Pointer to the root node of the tree whose size is measured
 *
 * Return: Size of the tree
 */
size_t binary_tree_size(const binary_tree_t *tree)
{
	if (tree)
	{
		size_t left_size = binary_tree_size(tree->left);
		size_t right_size = binary_tree_size(tree->right);

		return (1 + left_size + right_size);
	}
	return (0);
}
