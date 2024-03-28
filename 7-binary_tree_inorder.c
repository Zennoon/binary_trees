#include "binary_trees.h"

/**
 * binary_tree_inorder - Traverses a binary tree in in-order fashion, calling
 * a function for the value held in each node
 * @tree: Pointer to the root node of the tree to traverse
 * @func: The function to call for the values in the nodes
 *
 * Description: In-order traversal visits left-subtree then root then
 * right-subtree.
 * Return: void
 */
void binary_tree_inorder(const binary_tree_t *tree, void (*func)(int))
{
	if (tree && func)
	{
		binary_tree_inorder(tree->left, func);
		func(tree->n);
		binary_tree_inorder(tree->right, func);
	}
}
