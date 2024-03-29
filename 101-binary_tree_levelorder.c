#include "binary_trees.h"

#define QUEUE_SIZE 100

/**
 * struct queue_s - A simple queue implementation using an array
 * @q_arr: The queue (an array)
 * @front: The index of the first element in the queue
 * @rear: The current insertion index (index of last element + 1)
 */
typedef struct queue_s
{
	const binary_tree_t **q_arr;
	int front;
	int rear;
} queue_t;

/**
 * enqueue - Insert into a queue
 * @queue: Pointer to the queue to insert to
 * @node: The binary tree node to insert to the queue
 *
 * Return: void
 */
void enqueue(queue_t *queue, const binary_tree_t *node)
{
	if (queue->rear < QUEUE_SIZE && node)
	{
		queue->q_arr[queue->rear] = node;
		queue->rear++;
	}
}

/**
 * dequeue - Pop/dequeue from a queue
 * @queue: Pointer to the queue to dequeue from
 *
 * Return: void
 */
void dequeue(queue_t *queue)
{
	if (queue->front < queue->rear)
	{
		queue->front++;
	}
}

/**
 * top - Return the node on the top on a queue
 * @queue: Pointer to the queue whose top element is returned
 *
 * Return: Pointer to the binary tree node at the top of the queue, or
 * NULL if queue is empty
 */
const binary_tree_t *top(queue_t *queue)
{
	if (queue->front < queue->rear)
		return (queue->q_arr[queue->front]);
	return (NULL);
}

/**
 * binary_tree_levelorder - Traverses a binary tree in level-order fashion
 * using a queue
 * @tree: Pointer to the root node of the tree to traverse
 * @func: The function to call on every node's value
 *
 * Description: Level-order traversal visits all the nodes on the same level
 * before going down. It is breadth-first, as opposed to depth first
 * Return: void
 */
void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
	if (tree && func)
	{
		queue_t queue;

		queue.q_arr = malloc(sizeof(binary_tree_t *) * QUEUE_SIZE);
		queue.front = 0;
		queue.rear = 0;

		enqueue(&queue, tree);
		while (queue.front < queue.rear)
		{
			const binary_tree_t *top_node = top(&queue);

			func(top_node->n);
			enqueue(&queue, top_node->left);
			enqueue(&queue, top_node->right);
			dequeue(&queue);
		}
		free(queue.q_arr);
	}
}
