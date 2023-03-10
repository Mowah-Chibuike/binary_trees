#include "binary_trees.h"

/**
 * findMin - finds the minimun value in an avl tree
 * @root: pointer to the root node of the avl tree
 *
 * Return: the minimum value in a tree
 */
int findMin(avl_t *root)
{
	if (!root->left)
		return (root->n);
	return (findMin(root->left));
}

/**
 * avl_rebalance - rebalances an avl tree
 * @node: root node of the tree or subtree to balance
 *
 * Return: pointer to the root node of the tree
 */
avl_t *avl_rebalance(avl_t *node)
{
	int balance;
	avl_t *current, *grand_parent, *new_root = node;

	if (node == NULL)
		return (NULL);
	grand_parent = node->parent;
	balance = binary_tree_balance(node);
	if (balance > 1)
	{
		current = node->left;
		if (binary_tree_balance(current) > 0 || current->left)
			new_root = binary_tree_rotate_right(node);
		else if (binary_tree_balance(current) < 0)
		{
			node->left = binary_tree_rotate_left(current);
			new_root = binary_tree_rotate_right(node);
		}
	}
	else
	{
		current = node->right;
		if (binary_tree_balance(current) < 0 || current->right)
			new_root = binary_tree_rotate_left(node);
		else if (binary_tree_balance(current) > 0)
		{
			node->right = binary_tree_rotate_right(current);
			new_root = binary_tree_rotate_left(node);
		}
	}
	if (grand_parent)
	{
		if (grand_parent->left == node)
			grand_parent->left = new_root;
		else if (grand_parent->right == node)
			grand_parent->right = new_root;
	}
	return (new_root);
}

/**
 * avl_delete - deletes a node from an avl tree
 * @root: pointer to root node of the tree`
 * @value: value to be removed
 *
 * Return: new_root after deleting the node
 */
avl_t *avl_delete(avl_t *tree, avl_t *root, int value)
{
	avl_t *temp;
	int balance;

	if (root == NULL)
		return (NULL);
	if (value < root->n)
		root->left = avl_delete(tree, root->left, value);
	else if (value > root->n)
		root->right = avl_delete(tree, root->right, value);
	else
	{
		if (!root->left && !root->right)
		{
			free(root);
			return (NULL);
		}
		else if (!root->right)
		{
			temp = root->left;
			temp->parent = root->parent;
			free(root);
			root = temp;
		}
		else if (!root->left)
		{
			temp = root->right;
			temp->parent = root->parent;
			free(root);
			root = temp;
		}
		else
		{
			root->n = findMin(root->right);
			root->right = avl_delete(tree, root->right, root->n);
		}
	}
	balance = binary_tree_balance(root);
	if (balance > 1 || balance < -1)
		return (avl_rebalance(root));
	return (root);
}

/**
 * avl_remove - removes a node from an AVL tree
 * @root: pointer to the root node of the tree for removing a node
 * @value: value to remove in the tree
 *
 * Return:  pointer to the new root node of the tree after removing the desired
 * value, and after rebalancing
 */
avl_t *avl_remove(avl_t *root, int value)
{
	return (avl_delete(root, root, value));
}
