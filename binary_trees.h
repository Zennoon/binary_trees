#ifndef BINARY_TREES

#define BINARY_TREES

/** Header files **/
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

/** Struct and typedef definitions **/

/**
 * struct binary_tree_s - Binary tree node
 *
 * @n: Integer stored in the node
 * @parent: Pointer to the parent node
 * @left: Pointer to the left child of the node
 * @right: Pointer to the right child of the node
 */
struct binary_tree_s
{
	int n;
	struct binary_tree_s *parent;
	struct binary_tree_s *left;
	struct binary_tree_s *right;
};

typedef struct binary_tree_s binary_tree_t;
typedef struct binary_tree_s bst_t;
typedef struct binary_tree_s avl_t;
typedef struct binary_tree_s heap_t;

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

/** Function prototypes **/
void binary_tree_print(const binary_tree_t *);
binary_tree_t *binary_tree_node(binary_tree_t *, int);
binary_tree_t *binary_tree_insert_left(binary_tree_t *, int);
binary_tree_t *binary_tree_insert_right(binary_tree_t *, int);
void binary_tree_delete(binary_tree_t *);
int binary_tree_is_leaf(const binary_tree_t *);
int binary_tree_is_root(const binary_tree_t *);
void binary_tree_preorder(const binary_tree_t *, void (*)(int));
void binary_tree_inorder(const binary_tree_t *, void (*)(int));
void binary_tree_postorder(const binary_tree_t *, void (*)(int));
size_t binary_tree_height(const binary_tree_t *);
size_t binary_tree_depth(const binary_tree_t *);
size_t binary_tree_size(const binary_tree_t *);
size_t binary_tree_leaves(const binary_tree_t *);
size_t binary_tree_nodes(const binary_tree_t *);
int binary_tree_balance(const binary_tree_t *);
int binary_tree_is_full(const binary_tree_t *);
int binary_tree_is_perfect(const binary_tree_t *);
binary_tree_t *binary_tree_sibling(binary_tree_t *);
binary_tree_t *binary_tree_uncle(binary_tree_t *);
binary_tree_t *binary_trees_ancestor(const binary_tree_t *,
				     const binary_tree_t *);
void binary_tree_levelorder(const binary_tree_t *, void (*)(int));
int binary_tree_is_complete(const binary_tree_t *);
binary_tree_t *binary_tree_rotate_left(binary_tree_t *tree);

#endif
