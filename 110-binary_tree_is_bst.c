#include "binary_trees.h"

/**
 * is_bst - checks if a binary tree is a valid binary search tree
 * @tree: pointer to the root node of the tree to check
 * @minValue: the minimum value that should be stored in a tree
 * @maxValue: the maximum value that should be stored in a tree
 *
 * Return: 1 if tree is a valid BST, and 0 otherwise
 */
int is_bst(binary_tree_t *tree, int minValue, int maxValue)
{
	if (!tree)
		return (1);
	if (tree->n > minValue && tree->n < maxValue &&
			is_bst(tree->left, minValue, tree->n) &&
			is_bst(tree->right, tree->n, maxValue))
		return (1);
	return (0);
}

/**
 * binary_tree_is_bst - checks if a binary tree is a valid Binary Search Tree
 * @tree: pointer to the root node of the tree to check
 *
 * Return: 1 if tree is a valid BST, and 0 otherwise
 */
int binary_tree_is_bst(const binary_tree_t *tree)
{
	if (!tree)
		return (0);
	return (is_bst((binary_tree_t *)tree, INT_MIN, INT_MAX));
}
