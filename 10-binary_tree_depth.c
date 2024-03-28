#include "binary_trees.h"

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
