#include "binary_trees.h"

/**
 * binary_tree_postorder - Traverses a binary tree in post-order fashion,
 * calling a function for the value held in each node
 * @tree: Pointer to the root node of the tree to traverse
 * @func: The function to call for the values in the nodes
 *
 * Description: Post-order traversal visits left-subtree then right-subtree
 * then root.
 * Return: void
 */
void binary_tree_postorder(const binary_tree_t *tree, void (*func)(int))
{
	if (tree && func)
	{
		binary_tree_postorder(tree->left, func);
		binary_tree_postorder(tree->right, func);
		func(tree->n);
	}
}
