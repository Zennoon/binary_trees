#include "binary_trees.h"

/**
 * binary_trees_ancestor - Finds the lowest common ancestor of two nodes
 * @first: First node
 * @second: Second node
 *
 * Return: Lowest common ancestor of the two nodes, or NULL if none is found
 */
binary_tree_t *binary_trees_ancestor(const binary_tree_t *first,
				     const binary_tree_t *second)
{
	const binary_tree_t *tmp1 = first;

	while (tmp1)
	{
		const binary_tree_t *tmp2 = second;

		while (tmp2)
		{
			if (tmp1 == tmp2)
			{
				return ((binary_tree_t *) tmp1);
			}
			tmp2 = tmp2->parent;
		}
		tmp1 = tmp1->parent;
	}
	return (NULL);
}
