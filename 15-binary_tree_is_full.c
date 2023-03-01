#include "binary_trees.h"

/**
 * binary_tree_is_full - checks if a binary tree is full
 * @tree: pointer to the root node of the tree to check
 *
 * Return: 1 if tree is full, otherwise 0
 */
int binary_tree_is_full(const binary_tree_t *tree)
{
	int flag = 0;
	binary_tree_t *left, *right;

	if (tree)
	{
		left = tree->left;
		right = tree->right;
		if ((left && right) || (!left && !right))
			flag = 1;
		if (flag && left)
			flag = binary_tree_is_full(left);
		if (flag && right)
			flag = binary_tree_is_full(right);
	}
	return (flag);
}
