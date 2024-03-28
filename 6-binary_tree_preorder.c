#include "binary_trees.h"

/**
 * binary_tree_preorder - Traverses a binary tree in a preorder fashion, calling
 * a function for the value held in each node
 * @tree: Pointer to the root node of the tree to traverse
 * @func: The function to call for the values in the nodes
 *
 * Description: Preorder traversal visits root then left-subtree then
 * right-subtree.
 * Return: void
 */
void binary_tree_preorder(const binary_tree_t *tree, void (*func)(int))
{
	if (tree && func)
	{
		func(tree->n);
		binary_tree_preorder(tree->left, func);
		binary_tree_preorder(tree->right, func);
	}
}
