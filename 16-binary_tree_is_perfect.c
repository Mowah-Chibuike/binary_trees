#include "binary_trees.h"

/**
 * get_height - calculates the height of a binary tree recursively
 * @tree: pointer to the root node of the tree
 * @no_edges: number of egdes
 * @max_height: lowest height at every instance
 */
void height(
		const binary_tree_t *tree, int no_edges, int *max_height)
{
	if (tree)
	{
		height(tree->left, no_edges + 1, max_height);
		height(tree->right, no_edges + 1, max_height);
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
	int max_height = 0;

	height(tree, 0, &max_height);
	return (max_height);
}

/**
 * check_if_perfect - checks if a binary tree is perfect
 * @tree: pointer to the root node of the tree to check
 * @level: current level on the tree
 * @height: height of the binary tree
 *
 * Return: 1 if the tree is perfect, otherwise 0
 */
int check_if_perfect(const binary_tree_t *tree, int level, int height)
{
	int flag = 0;
	binary_tree_t *left, *right;

	if (tree)
	{
		left = tree->left;
		right = tree->right;
		if ((left && right) || (!left && !right))
			flag = 1;
		if ((!left && !right) && (level != height))
			flag = 0;
		if (flag && left)
			flag = check_if_perfect(left, level + 1, height);
		if (flag && right)
			flag = check_if_perfect(right, level + 1, height);
	}
	return (flag);
}

/**
 * binary_tree_is_perfect - checks if a binary tree is perfect
 * @tree: pointer to the root node of the tree to check
 *
 * Return: 1 if the tree is perfect, otherwise 0
 */
int binary_tree_is_perfect(const binary_tree_t *tree)
{
	int height, res;

	height = tree_height(tree);
	res = check_if_perfect(tree, 0, height);
	return (res);
}
