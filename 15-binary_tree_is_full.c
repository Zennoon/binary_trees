#include "binary_trees.h"

/**
 * binary_tree_is_full - Checks if a given binary tree is full or not
 * @tree: Pointer to the root of the binary tree which is checked for fullness
 *
 * Description: A binary tree is full if every node in the tree has either zero
 * or two nodes
 * Return: 1 if the tree is full, 0 otherwise
 */
int binary_tree_is_full(const binary_tree_t *tree)
{
	if (tree)
	{
		if (tree->left || tree->right)
		{
			int left_is_full, right_is_full;

			if (!(!tree->left) ^ !(!tree->right))
				return (0);
			left_is_full = binary_tree_is_full(tree->left);
			right_is_full = binary_tree_is_full(tree->right);
			return (left_is_full && right_is_full);
		}
		return (1);
	}
	return (0);
}
