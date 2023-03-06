#include "binary_trees.h"

/**
 * array_to_bst - buils Binary Search Tree from an array
 * @array: array of integers to be converted
 * @size: size of the array
 *
 * Return: pointer to the root node of the created BST, otherwise NULL
 */
bst_t *array_to_bst(int *array, size_t size)
{
	size_t i;
	bst_t *root = NULL, *node;

	for (i = 0; i < size; i++)
	{
		node = bst_insert(&root, array[i]);
		if (!node)
			continue;
	}
	return (root);
}
