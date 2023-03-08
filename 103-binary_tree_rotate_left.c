#include "binary_trees.h"

/**
 * tree_insert - inserts a node into a balanced binary tree
 * @tree: tree to insert into
 * @node: node to be inserted
 */
void tree_insert(binary_tree_t *tree, binary_tree_t *node)
{
	if (tree)
	{
		if (node->n <= tree->n)
		{
			if (tree->left)
				tree_insert(tree->left, node);
			else
			{
				tree->left = node;
				node->parent = tree;
			}
		}
		else
		{
			if (tree->right)
				tree_insert(tree->right, node);
			else
			{
				tree->right = node;
				node->parent = tree;
			}
		}
	}
}

/**
 * binary_tree_rotate_left - performs a left-rotation on a binary tree
 * @tree: pointer to the root node of the tree to rotate
 *
 * Return: pointer to the new root node of the tree once rotated
 */
binary_tree_t *binary_tree_rotate_left(binary_tree_t *tree)
{
	binary_tree_t *new_root, *temp;

	if (!tree || !tree->right)
		return (tree);
	new_root = tree->right;
	tree->right = NULL;
	temp = new_root->left;
	new_root->parent = tree->parent;
	tree->parent = new_root;
	new_root->left = tree;
	if (temp)
		tree_insert(tree, temp);
	return (new_root);
}
