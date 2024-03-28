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

/** Function prototypes **/
void binary_tree_print(const binary_tree_t *);
binary_tree_t *binary_tree_node(binary_tree_t *, int);

#endif