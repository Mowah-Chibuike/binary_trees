#include "binary_trees.h"

/**
 * max - returns the largest between two integers
 * @x: the first integer
 * @y: the second integer
 *
 * Return: the largest between two integers
 */
int max(int x, int y)
{
	if (x < y)
		return (y);
	return (x);
}

/**
 * find_height - finds the height of a binary tree
 * @tree: root node of the tree or subtree to check the height
 *
 * Return: return the height of a boinary tree
 */
int find_height(binary_tree_t *tree)
{
	if (tree == NULL)
		return (-1);
	return (max(find_height(tree->left), find_height(tree->right)) + 1);
}

/**
 * balance_factor - calculates the balance factor of a tree
 * @root: root node of the binary tree
 *
 * Return: the balance factor of the binary tree
 */
int balance_factor(binary_tree_t *node)
{
	int left, right;

	left = find_height(node->left) + 1;
	right = find_height(node->right) + 1;
	return (left - right);
}

/**
 * is_avl - checks if a binary search tree is an avl tree
 * @tree: the root node of the binary search tree
 * @min: the minimum value in the binary tree
 * @max: the maximum value in the binary tree
 *
 * Return: 1 if the tree is an avl tree, otherwise 0
 */
int is_avl(binary_tree_t *tree, int min, int max)
{
	int left, right;

	if (!tree)
		return (1);
	if (tree->n > min && tree->n < max)
	{
		if (tree->left)
		{
			left = balance_factor(tree->left);
			if (left < -1 || left > 1)
				return (0);
		}
		if (tree->right)
		{
			right = balance_factor(tree->right);
			if (right < -1 || right > 1)
				return (0);
		}
		return (is_avl(tree->left, min, tree->n) &&
			is_avl(tree->right, tree->n, max));
	}
	return (0);
}

/**
 * binary_tree_is_avl - checks if a binary tree is a valid AVL Tree
 * @tree: pointer to the root node of the tree to check
 *
 * Return: 1 if tree is a valid AVL Tree, and 0 otherwise
 */
int binary_tree_is_avl(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);
	return (is_avl((binary_tree_t *)tree, INT_MIN, INT_MAX));
}
