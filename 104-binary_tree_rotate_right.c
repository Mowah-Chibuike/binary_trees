#include "binary_trees.h"

/**
 * b_tree_insert - inserts a node into a balanced binary tree
 * @tree: tree to insert into
 * @node: node to be inserted
 */
void b_tree_insert(binary_tree_t *tree, binary_tree_t *node)
{
	if (tree)
	{
		if (node->n <= tree->n)
		{
			if (tree->left)
				b_tree_insert(tree->left, node);
			else
			{
				tree->left = node;
				node->parent = tree;
			}
		}
		else
		{
			if (tree->right)
				b_tree_insert(tree->right, node);
			else
			{
				tree->right = node;
				node->parent = tree;
			}
		}
	}
}

/**
 * binary_tree_rotate_right - performs a right-rotation on a binary tree
 * @tree: pointer to the root node of the tree to rotate
 *
 * Return: pointer to the new root node of the tree once rotated
 */
binary_tree_t *binary_tree_rotate_right(binary_tree_t *tree)
{
	binary_tree_t *new_root, *temp;

	if (!tree || !tree->left)
		return (tree);
	new_root = tree->left;
	tree->left = NULL;
	temp = new_root->right;
	new_root->parent = tree->parent;
	tree->parent = new_root;
	new_root->right = tree;
	if (temp)
		b_tree_insert(tree, temp);
	return (new_root);
}
