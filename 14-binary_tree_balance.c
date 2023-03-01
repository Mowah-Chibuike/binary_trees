#include "binary_trees.h"

/**
 * find_height - calculates the height of a binary tree recursively
 * @tree: pointer to the root node of the tree
 * @no_edges: number of egdes
 * @max_height: lowest height at every instance
 */
void find_height(const binary_tree_t *tree, int no_edges, int *max_height)
{
	if (tree)
	{
		find_height(tree->left, no_edges + 1, max_height);
		find_height(tree->right, no_edges + 1, max_height);
		if (no_edges > *max_height)
			*max_height = no_edges;
	}
}

/**
 * tree_height - measures the height of a binary tree
 * @tree: pointer to the root node of the tree to measure the height.
 *
 * Return: the height of the tree
 */
int tree_height(const binary_tree_t *tree)
{
	int max_height;

	max_height = 0;
	find_height(tree, 0, &max_height);
	return (max_height);
}

/**
 * binary_tree_balance - measures the balance factor of a binary tree
 * @tree: pointer to the root node of the tree to measure the balance factor
 *
 * Return: the balance factor of the tree
 */
int binary_tree_balance(const binary_tree_t *tree)
{
	int balance = 0, lh, rh;

	if (tree)
	{
		lh = tree_height(tree->left);
		if (tree->left)
			lh++;
		rh = tree_height(tree->right);
		if (tree->right)
			rh++;
		balance = lh - rh;
	}
	return (balance);
}
