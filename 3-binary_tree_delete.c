#include "binary_trees.h"

/**
 * binary_tree_delete - Deletes (frees) an entire binary tree with root given
 * @tree: Pointer to the root node of the tree to delete
 *
 * Return: void
 */
void binary_tree_delete(binary_tree_t *tree)
{
	if (tree)
	{
		binary_tree_delete(tree->left);
		binary_tree_delete(tree->right);
		free(tree);
	}
}
