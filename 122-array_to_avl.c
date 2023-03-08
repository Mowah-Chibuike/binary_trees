#include "binary_trees.h"

/**
 * array_to_avl - builds an AVL tree from an array
 * @array: array of integers to be converted
 * @size: size of the array
 *
 * Return: pointer to the root node of the created AVL tree, or NULL
 */
avl_t *array_to_avl(int *array, size_t size)
{
	size_t i;
	avl_t *root = NULL;

	if (array == NULL)
		return (NULL);
	for (i = 0; i < size; i++)
		avl_insert(&root, array[i]);
	return (root);
}
