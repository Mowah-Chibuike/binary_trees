#include "binary_trees.h"

/**
 * binary_tree_uncle - finds the uncle of a node
 * @node: pointer to the node to find the uncle
 *
 * Return: a pointer to the uncle node, otherwise NULL
 */
binary_tree_t *binary_tree_uncle(binary_tree_t *node)
{
	binary_tree_t *parent, *grand_parent;

	if (node == NULL)
		return (NULL);
	parent = node->parent;
	if (!parent || !parent->parent)
		return (NULL);
	grand_parent = parent->parent;
	if (grand_parent->left == parent)
		return (grand_parent->right);
	return (grand_parent->left);
}
