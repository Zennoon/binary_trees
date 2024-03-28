#include "binary_trees.h"

/**
 * binary_tree_insert_left - Creates and inserts a node as the left child of
 * another node a pointer to which is given
 * @parent: Pointer to the node to insert a left child in
 * @value: The value to be stored in the new node
 *
 * Description: If the parent node already has a left child, it is replaced
 * with the new one, and the old child becomes the left child of this new node.
 * Return: Pointer to the new node on success, NULL otherwise
 */
binary_tree_t *binary_tree_insert_left(binary_tree_t *parent, int value)
{
	binary_tree_t *new_node;

	if (!parent)
		return (parent);
	new_node = malloc(sizeof(binary_tree_t));
	if (new_node)
	{
		new_node->n = value;
		new_node->parent = parent;
		new_node->left = NULL;
		new_node->right = NULL;

		if (parent->left)
		{
			new_node->left = parent->left;
			(parent->left)->parent = new_node;
		}
		parent->left = new_node;
	}
	return (new_node);
}
