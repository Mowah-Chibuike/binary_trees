#include "binary_trees.h"

/**
 * create_from_sorted - creates an avl tree from a sorted array
 * @parent: double pointer of the node to be inserted
 * @array: array of integers
 * @start: the start index of the array or subarray
 * @end: the end index of the array or subarray
 *
 * Return: pointer to the created node
 */
avl_t *create_from_sorted(avl_t **parent, int *array, int start, int end)
{
	int mid;
	avl_t *new_node;

	mid = (start + end + 1) / 2;
	new_node = binary_tree_node(*parent, array[mid]);
	if (!new_node)
		return (NULL);
	if (*parent == NULL)
		*parent = new_node;
	if (mid > 0 && mid < end)
	{
		new_node->left = create_from_sorted(&new_node, array, start, mid - 1);
		new_node->right = create_from_sorted(&new_node, array, mid + 1, end);
	}
	return (new_node);
}

/**
 * sorted_array_to_avl - builds an AVL tree from an array
 * @array: array to be converted
 * @size: size of the array
 *
 * Return: pointer to the root node of the created AVL tree, or NULL on failure
 */
avl_t *sorted_array_to_avl(int *array, size_t size)
{
	avl_t *root = NULL;

	if (array == NULL)
		return (NULL);
	create_from_sorted(&root, array, 0, (int)size - 1);
	return (root);
}
