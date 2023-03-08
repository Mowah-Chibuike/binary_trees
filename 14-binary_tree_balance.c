#include "binary_trees.h"

/**
 * max - finds the larger between two integers
 * @a: the first integer
 * @b: the second integer
 *
 * Return: the larger between two integers
 */
int max(int a, int b)
{
	if (a < b)
		return (b);
	return (a);
}

/**
 * find_height - calculates the height of a binary tree recursively
 * @tree: pointer to the root node of the tree
 * 
 * Return: the height of the tree
 */
int find_height(const binary_tree_t *tree)
{
	int left, right;

	if (!tree)
		return (-1);
	left = find_height(tree->left);
	right = find_height(tree->right);
	return (max(left, right) + 1);
}

/**
 * binary_tree_balance - measures the balance factor of a binary tree
 * @tree: pointer to the root node of the tree to measure the balance factor
 *
 * Return: the balance factor of the tree
 */
int binary_tree_balance(const binary_tree_t *tree)
{
	int lh, rh;

	lh = find_height(tree->left) + 1;
	rh = find_height(tree->right) + 1;
	return (lh - rh);
}
