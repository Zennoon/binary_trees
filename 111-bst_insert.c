#include "binary_trees.h"

/**
 * bst_insert - Inserts a value in a binary search tree
 * @tree: Douple pointer to the tree to insert to
 * @value: The value to insert to the tree
 *
 * Return: Pointer to the new node on success, NULL on failure
 */
bst_t *bst_insert(bst_t **tree, int value)
{
	bst_t *nodeptr = *tree, *parent = NULL, *new_node;

	while (nodeptr)
	{
		parent = nodeptr;
		if (nodeptr->n > value)
			nodeptr = nodeptr->left;
		else if (nodeptr->n < value)
			nodeptr = nodeptr->right;
		else
			return (NULL);
	}
	new_node = binary_tree_node(parent, value);
	if (new_node)
	{
		if (parent && value < parent->n)
			parent->left = new_node;
		else if (parent)
			parent->right = new_node;
		if (!*tree)
			*tree = new_node;
	}
	return (new_node);
}
