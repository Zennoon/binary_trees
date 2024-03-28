#include "binary_trees.h"

/**
 * binary_tree_node - Creates (dynamically) a binary tree node
 * @parent: Parent of the created node
 * @value: The value to be stored in the node
 *
 * Return: Pointer to the new node if successful, NULL otherwise
 */
binary_tree_t *binary_tree_node(binary_tree_t *parent, int value)
{
	binary_tree_t *new_node = malloc(sizeof(binary_tree_t));

	if (new_node)
	{
		new_node->n = value;
		new_node->parent = parent;
		new_node->left = NULL;
		new_node->right = NULL;
	}
	return (new_node);
}
