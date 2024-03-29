#include "binary_trees.h"

/**
 * binary_tree_rotate_right - Performs a right rotation on a binary tree
 * @tree: Pointer to the root node of the tree to rotate
 *
 * Return: Pointer to the new root node after the rotation
 */
binary_tree_t *binary_tree_rotate_right(binary_tree_t *tree)
{
	if (tree && tree->left)
	{
		binary_tree_t *tmp;

		tmp = tree->left;
		tmp->parent = tree->parent;
		tree->left = tmp->right;
		if (tmp->right)
			tmp->right->parent = tree;
		tmp->right = tree;
		tree->parent = tmp;
		tree = tmp;
	}
	return (tree);
}
