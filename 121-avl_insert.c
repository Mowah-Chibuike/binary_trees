#include "binary_trees.h"

/**
 * _insert -  inserts a value in a Binary Search Tree
 * @tree: double pointer to the root node of the BST to insert the value
 * @value: value to store in the node to be inserted
 *
 * Return:  pointer to the created node, or NULL on failure
 */
avl_t *_insert(avl_t **tree, int value)
{
	avl_t *new_node;

	if (tree == NULL)
		return (NULL);
	if (*tree == NULL)
		new_node = *tree = binary_tree_node(NULL, value);
	else if (value < (*tree)->n)
	{
		if ((*tree)->left)
			new_node = _insert(&(*tree)->left, value);
		else
			new_node = (*tree)->left = binary_tree_node(*tree, value);
	}
	else if (value > (*tree)->n)
	{
		if ((*tree)->right)
			new_node = _insert(&(*tree)->right, value);
		else
			new_node = (*tree)->right = binary_tree_node(*tree, value);
	}
	else
		return (NULL);
	return (new_node);
}

/**
 * avl_insert - inserts a value in an AVL Tree
 * @tree: double pointer to the root node of the AVL tree for inserting the
 * value
 * @value: value to store in the node to be inserted
 *
 * Return: return a pointer to the created node, or NULL on failure
 */
avl_t *avl_insert(avl_t **tree, int value)
{
	avl_t *new_node, *current, *parent, *grand_parent, *new_root = NULL;

	new_node = current = _insert(tree, value);
	if (new_node == NULL)
		return (NULL);
	parent = new_node->parent;
	while (parent)
	{
		grand_parent = parent->parent;
		if (parent->right == current)
		{
			if (binary_tree_balance(parent) < -1)
			{
				if (binary_tree_balance(current) < 0)
					new_root = binary_tree_rotate_left(parent);
				else if (binary_tree_balance(current) > 0)
				{
					parent->right = binary_tree_rotate_right(current);
					new_root = binary_tree_rotate_left(parent);
				}
			}
		}
		else if (parent->left == current)
		{
			if (binary_tree_balance(parent) > 1)
			{
				if (binary_tree_balance(current) > 0)
					new_root = binary_tree_rotate_right(parent);
				else if (binary_tree_balance(current) < 0)
				{
					parent->left = binary_tree_rotate_left(current);
					new_root = binary_tree_rotate_right(parent);
				}
			}
		}
		if (grand_parent)
		{
			if (new_root)
			{
				if (grand_parent->right == parent)
					grand_parent->right = new_root;
				else
					grand_parent->left = new_root;
				break;
			}
		}
		else
			if (new_root)
			{
				*tree = new_root;
				break;
			}
		current = parent;
		parent = grand_parent;

	}
	return (new_node);
}
