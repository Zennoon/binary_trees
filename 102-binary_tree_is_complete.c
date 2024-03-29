#include "binary_trees.h"

#define QUEUE_SIZE 100

/**
 * enqueue1 - Insert into a queue
 * @queue: Pointer to the queue to insert to
 * @node: The binary tree node to insert to the queue
 *
 * Return: void
 */
void enqueue1(queue_t *queue, const binary_tree_t *node)
{
	if (queue->rear < QUEUE_SIZE && node)
	{
		queue->q_arr[queue->rear] = node;
		queue->rear++;
	}
}

/**
 * dequeue1 - Pop/dequeue from a queue
 * @queue: Pointer to the queue to dequeue from
 *
 * Return: void
 */
void dequeue1(queue_t *queue)
{
	if (queue->front < queue->rear)
	{
		queue->front++;
	}
}

/**
 * top1 - Return the node on the top on a queue
 * @queue: Pointer to the queue whose top element is returned
 *
 * Return: Pointer to the binary tree node at the top of the queue, or
 * NULL if queue is empty
 */
const binary_tree_t *top1(queue_t *queue)
{
	if (queue->front < queue->rear)
		return (queue->q_arr[queue->front]);
	return (NULL);
}

/**
 * binary_tree_is_complete - Checks if a binary tree is complete
 * @tree: Pointer to the root node of the tree to check for completeness
 *
 * Description: A binary tree is complete if all the levels except the last
 * must be filled, and the nodes are pushed to the left side
 * Return: 1 if the tree is complete, 0 otherwise (even if the tree is NULL)
 */
int binary_tree_is_complete(const binary_tree_t *tree)
{
	queue_t queue;
	int leaf_found = 0, is_complete = 0, breaked = 0;

	queue.q_arr = malloc(sizeof(binary_tree_t *) * QUEUE_SIZE);
	queue.front = 0;
	queue.rear = 0;

	if (tree)
	{
		enqueue1(&queue, tree);
		while (queue.front < queue.rear)
		{
			const binary_tree_t *top_node = top1(&queue);

			if (leaf_found && (top_node->left || top_node->right))
			{
				breaked = 1;
				break;
			}
			if (!top_node->left || !top_node->right)
			{
				if (!top_node->left && top_node->right)
				{
					breaked = 1;
					break;
				}
				leaf_found = 1;
			}
			enqueue1(&queue, top_node->left);
			enqueue1(&queue, top_node->right);
			dequeue1(&queue);
		}
		if (!breaked)
			is_complete = 1;
	}
	free(queue.q_arr);
	return (is_complete);
}
