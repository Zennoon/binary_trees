#include "binary_trees.h"

/**
 * get_max - Returns the maximum of two positive numbers
 * @n1: First number
 * @n2: Second number
 *
 * Return: The greatest of the two arguments
 */
size_t get_max(size_t n1, size_t n2)
{
	if (n1 >= n2)
		return (n1);
	return (n2);
}

/**
 * get_tree_height - Returns the height of a binary tree
 * @tree: Pointer to the root node of the tree to measure
 *
 * Description: Height of a tree is the length of the longest path from a root
 * to a leaf.
 * Return: Height of the given binary tree
 */
size_t get_tree_height(const binary_tree_t *tree)
{
	if (tree && (tree->left || tree->right))
	{
		size_t left_height = 1 + get_tree_height(tree->left);
		size_t right_height = 1 + get_tree_height(tree->right);

		return (get_max(left_height, right_height));
	}
	return (0);
}

/**
 * binary_tree_balance - Returns the balance factor of a given binary tree
 * @tree: Pointer to the root of the tree whose balance factor is computed
 *
 * Description: Balancefactor = left subtree height - right subtree height
 * Return: Balance factor of the tree
 */
int binary_tree_balance(const binary_tree_t *tree)
{
	size_t l_height = 0, r_height = 0;

	if (tree)
	{
		l_height = get_tree_height(tree->left) + (tree->left != NULL);
		r_height = get_tree_height(tree->right) + (tree->right != NULL);
	}
	return ((int) l_height - (int) r_height);
}
