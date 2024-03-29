#include "binary_trees.h"

/**
 * binary_tree_rotate_left - Performs a left rotation on a binary tree
 * @tree: Pointer to the root node of the tree to rotate
 *
 * Return: Pointer to the new root node after the rotation
 */
binary_tree_t *binary_tree_rotate_left(binary_tree_t *tree)
{
	if (tree && tree->right)
	{
		binary_tree_t *tmp;

		tmp = tree->right;
		tmp->parent = tree->parent;
		tree->right = tmp->left;
		if (tmp->left)
			tmp->left->parent = tree;
		tmp->left = tree;
		tree->parent = tmp;
		tree = tmp;
	}
	return (tree);
}
