#include "binary_trees.h"

/**
 * bst_insert -  inserts a value in a Binary Search Tree
 * @tree: double pointer to the root node of the BST to insert the value
 * @value: value to store in the node to be inserted
 *
 * Return:  pointer to the created node, or NULL on failure
 */
bst_t *bst_insert(bst_t **tree, int value)
{
	bst_t *new_node;

	if (tree == NULL)
		return (NULL);
	if (*tree == NULL)
		new_node = *tree = binary_tree_node(NULL, value);
	else if (value < (*tree)->n)
	{
		if ((*tree)->left)
			new_node = bst_insert(&(*tree)->left, value);
		else
			new_node = (*tree)->left = binary_tree_node(*tree, value);
	}
	else if (value > (*tree)->n)
	{
		if ((*tree)->right)
			new_node = bst_insert(&(*tree)->right, value);
		else
			new_node = (*tree)->right = binary_tree_node(*tree, value);
	}
	else
		return (NULL);
	return (new_node);
}
