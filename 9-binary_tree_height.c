#include "binary_trees.h"

/**
 * findheight - calculates the height of a binary tree recursively
 * @tree: pointer to the root node of the tree
 * @no_edges: number of egdes
 * @max_height: lowest height at every instance
 */
void find_height(const binary_tree_t *tree, size_t no_edges, size_t *max_height)
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
 * binary_tree_height - measures the height of a binary tree
 * @tree: pointer to the root node of the tree to measure the height.
 *
 * Return: the height of the tree
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t max_height;

	max_height = 0;
	find_height(tree, 0, &max_height);
	return (max_height);
}
