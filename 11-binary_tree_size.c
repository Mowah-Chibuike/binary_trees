#include "binary_trees.h"

/**
 * _size - returns the size of a binary tree
 * @tree: pointer to the root node of the tree
 * @iter: number of function calls
 *
 * Return: size of a binary tree
 */
size_t _size(const binary_tree_t *tree, int iter)
{
	size_t count = 0;

	if (tree)
	{
		if (iter == 0)
			count++;
		if (tree->left)
			count++;
		if (tree->right)
			count++;
		count += _size(tree->left, iter + 1) + _size(tree->right, iter + 1);
	}
	return (count);
}

/**
 * binary_tree_size - measures the size of a binary tree
 * @tree: pointer to the root node of the tree to measure the size
 *
 * Return: the size of the binary tree
 */
size_t binary_tree_size(const binary_tree_t *tree)
{
	return (_size(tree, 0));
}
