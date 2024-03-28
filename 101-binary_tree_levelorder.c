#include "binary_trees.h"

typedef struct queue
{
	const binary_tree_t **arr;
	int front;
	int rear;
} queue;

void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
	queue q;

	q.arr = malloc(sizeof(binary_tree_t *) * 500);
	q.front = 0;
	q.rear = 0;
	if (tree)
	{
		q.arr[q.rear] = tree;
		q.rear += 1;
	}

	while (q.front < q.rear)
	{
		q.front += 1;
		if (q.arr[q.front - 1]->left)
		{
			q.arr[q.rear] = q.arr[q.front - 1]->left;
			q.rear += 1;
		}
		if (q.arr[q.front - 1]->right)
		{
			q.arr[q.rear] = q.arr[q.front - 1]->right;
			q.rear += 1;
		}
		func(q.arr[q.front - 1]->n);
	}
	free(q.arr);
}
