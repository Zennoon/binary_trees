#include "binary_trees.h"

/**
 * check_bst - Checks if a binary tree is a binary search tree
 * @tree: The tree to check
 *
 * Return: 1 if the tree is a bst, 0 otherwise (even if tree is NULL)
 */
int check_bst(const binary_tree_t *tree)
{
	if (tree)
	{
		if ((tree->left && tree->n <= tree->left->n) ||
		    (tree->right && tree->n >= tree->right->n))
			return (0);
		if (tree->parent && tree->parent->parent)
		{
			if (tree->parent == tree->parent->parent->left &&
			    tree->n >= tree->parent->parent->n)
				return (0);
			if (tree->parent == tree->parent->parent->right &&
			    tree->n <= tree->parent->parent->n)
				return (0);
		}
		return (check_bst(tree->left) && check_bst(tree->right));
	}
	return (1);
}

/**
 * binary_tree_is_bst - Checks if a given binary tree is a binary search tree
 * @tree: The tree to check
 *
 * Description: A binary search tree is a binary tree where each node's value
 * is greater than each node's value in its left subtree, and less than each
 * node's value in its right subtree
 * Return: 1 if the tree is a bst, 0 otherwise (even if tree is NULL)
 */
int binary_tree_is_bst(const binary_tree_t *tree)
{
	if (!tree)
		return (0);
	return (check_bst(tree));
}
