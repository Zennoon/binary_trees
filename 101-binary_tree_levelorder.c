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

/**
 * binary_tree_depth - Measures the depth of a given node in a binary tree
 * @tree: Pointer to the node whose depth is measured
 *
 * Description: Depth of a node is the number of edges between the root of the
 * tree and the node
 * Return: Depth of the node in the tree
 */
size_t binary_tree_depth(const binary_tree_t *tree)
{
	if (tree && tree->parent)
	{
		return (1 + binary_tree_depth(tree->parent));
	}
	return (0);
}

/**
 * binary_tree_pre_order - Traverses a binary tree in preorder fashion, calling
 * a function for the value held in each node
 * @tree: Pointer to the root node of the tree to traverse
 * @func: The function to call for the values in the nodes
 *
 * Description: Pre-order traversal visits root then left-subtree then
 * right-subtree.
 * Return: void
 */
void binary_tree_pre_order(const binary_tree_t *tree, void (*func)(int),
			   size_t h, size_t d)
{
        if (tree && func)
        {
		if (binary_tree_depth(tree) == d)
			func(tree->n);
                binary_tree_pre_order(tree->left, func, h, d);
                binary_tree_pre_order(tree->right, func, h, d);
        }
}

/**
 * binary_tree_levelorder - Traverses a binary tree in level-order fashion
 * @tree: Pointer to the root node of the tree to traverse
 * @func: Function to be called on each node's value
 *
 * Description: Level-order traversal visits nodes in the same level (depth)
 * before going down
 * Return: void
 */
void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
	size_t h = binary_tree_height(tree), d;

	for (d = 0; d <= h; d++)
		binary_tree_pre_order(tree, func, h, d);
}
