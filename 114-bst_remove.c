#include "binary_trees.h"

/**
 *
 */
int findMin(bst_t *root)
{
	if (root->left == NULL)
		return (root->n);
	return (findMin(root->left));
}

/**
 * bst_remove - removes a node from a Binary Search Tree
 * @root: pointer to the root node of the tree where you will remove a node
 * @value: value to remove in the tree
 *
 * Return: pointer to the new root node of the tree after removing the
 * desired value
 */
bst_t *bst_remove(bst_t *root, int value)
{
	bst_t *temp;

	if (root == NULL)
		return (NULL);
	else if (root->n > value)
		root->left = bst_remove(root->left, value);
	else if (root->n < value)
		root->right = bst_remove(root->right, value);
	else
	{
		if (!root->right && !root->left)
		{
			free(root);
			root = NULL;
		}
		else if (root->right == NULL)
		{
			temp = root->left;
			free(root);
			root = temp;
		}
		else if (root->left == NULL)
		{
			temp = root->right;
			free(root);
			root = temp;
		}
		else
		{
			root->n = findMin(root->right);
			root->right = bst_remove(root->right, root->n);
		}
	}
	return (root);
}
