#include "binary_trees.h"

/**
 * binary_tree_insert_right - Creates and inserts a node as the right child of
 * another node a pointer to which is given
 * @parent: Pointer to the node to insert a right child in
 * @value: The value to be stored in the new node
 *
 * Description: If the parent node already has a right child, it is replaced
 * with the new one, and the old child becomes the right child of this new node.
 * Return: Pointer to the new node on success, NULL otherwise
 */
binary_tree_t *binary_tree_insert_right(binary_tree_t *parent, int value)
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

		if (parent->right)
		{
			new_node->right = parent->right;
			(parent->right)->parent = new_node;
		}
		parent->right = new_node;
	}
	return (new_node);
}
