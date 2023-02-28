#ifndef STRUCTS_H
#define STRUCTS_H

/**
 * struct binary_tree_s - Binary tree node
 *
 * @n: Integer stored in the node
 * @parent: Pointer to the parent node
 * @left: Pointer to the left child node
 * @right: Pointer to the right child node
 */
struct binary_tree_s
{
	int n;
	struct binary_tree_s *parent;
	struct binary_tree_s *left;
	struct binary_tree_s *right;
};

/**
 * binary_tree_t - Basic binary tree
 */
typedef struct binary_tree_s binary_tree_t;

/**
 * bst_t - Binary Search Tree
 */
typedef struct binary_tree_s bst_t;

/**
 * avl_t - AVL Tree
 */
typedef struct binary_tree_s avl_t;

/**
 * heap_t - Max Binary Heap
 */
typedef struct binary_tree_s heap_t;

#endif /* STRUCTS_H */
