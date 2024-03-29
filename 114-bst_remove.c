#include "binary_trees.h"

/**
 * in_order_successor - Finds the in-order successor of a given node
 * @node: The node of a binary search tree whose successor is sought
 *
 * Return: The in-order successor of the node
 */
bst_t *in_order_successor(bst_t *node)
{
	bst_t *successor = node->right;

	while (successor->left)
		successor = successor->left;
	return (successor);
}

/**
 * bst_search1 - Searches for and returns a node with a given value from a BST
 * @tree: Pointer to the root node of the BST to search inside
 * @value: The value to search
 *
 * Return: The node holding the desired value, or NULL if not found
 */
bst_t *bst_search1(const bst_t *tree, int value)
{
	bst_t *node = (bst_t *) tree;

	while (node)
	{
		if (node->n == value)
			break;
		else if (node->n > value)
			node = node->left;
		else
			node = node->right;
	}
	return (node);
}

/**
 * bst_replace - Replaces one node with its successor
 * @node: The node to be replaced
 * @successor: The node replacing @node
 *
 * Return: void
 */
void bst_replace(bst_t *node, bst_t *successor)
{
	bst_t *node_parent = node->parent;
	if (!successor)
	{
		if (node == node_parent->left)
			node_parent->left = NULL;
		else
			node_parent->right = NULL;
	}
	else
	{
		bst_t *s_parent = successor->parent;

		if (successor == s_parent->left)
			s_parent->left = NULL;
		else
			s_parent->right = NULL;
		if (successor->right)
			successor->right->parent = s_parent;
		successor->parent = node_parent;
		if (node_parent && node == node_parent->left)
			node_parent->left = successor;
		else if (node_parent)
			node_parent->right = successor;
		if (node->left && node->left != successor)
		{
			successor->left = node->left;
			node->left->parent = successor;
		}
		if (node->right && node->right != successor)
		{
			successor->right = node->right;
			node->right->parent = successor;
		}
	}
}

/**
 * bst_remove - Removes a node from a binary search tree
 * @root: Pointer to the root node of the BST tree to remove from
 * @value: Value to remove from the tree
 *
 * Return: Pointer to the new root node after the removal
 */
bst_t *bst_remove(bst_t *root, int value)
{
	bst_t *node = bst_search1(root, value);

	if (node)
	{
		bst_t *successor = NULL;

		if (node->left && node->right)
			successor = in_order_successor(node);
		else if (node->left)
			successor = node->left;
		else if (node->right)
			successor = node->right;

		bst_replace(node, successor);
		root = node;
		while (root->parent)
			root = root->parent;
		free(node);
	}
	return (root);
}
