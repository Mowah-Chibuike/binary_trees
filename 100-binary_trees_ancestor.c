#include "binary_trees.h"

/**
 * binary_trees_ancestor - finds the lowest common ancestor of two nodes
 * @first: pointer to the first node
 * @second: pointer to the second node
 *
 * Return: pointer to the lowest common ancestor node of the two given nodes
 * or NULL
 */
binary_tree_t *binary_trees_ancestor(
		const binary_tree_t *first, const binary_tree_t *second)
{
	binary_tree_t *first_parent, *second_parent;

	if (!first || !second)
		return (NULL);
	first_parent = first->parent;
	second_parent = second->parent;
	if (!first_parent || !second_parent)
		return (NULL);
	while (first_parent)
	{
		while (second_parent)
		{
			if (first == second_parent)
				return ((binary_tree_t *)first);
			else if (first_parent == second_parent)
				return (first->parent);
			second_parent = second_parent->parent;
		}
		first_parent = first_parent->parent;
	}
	return (NULL);
}
