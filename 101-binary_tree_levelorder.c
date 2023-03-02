#include "binary_trees.h"

/**
 * queue_push - pushes a node onto the stack
 * @tail: double pointer to the tail of the queue
 * @node: value to be pushed to the queue
 *
 * Return: pointer to node added to the queue
 */
queue_t *queue_push(queue_t **tail, binary_tree_t *node)
{
	queue_t *new_node, *former;

	new_node = (queue_t *)malloc(sizeof(queue_t));
	new_node->node = node;
	new_node->next = NULL;
	if (*tail)
	{
		former = *tail;
		former->next = new_node;
	}
	*tail = new_node;
	return (new_node);
}

/**
 * queue_pop - pops a node of the queue
 * @head: double pointer to the head node of the queue
 */
void queue_pop(queue_t **head)
{
	queue_t *temp = *head;

	*head = temp->next;
	free(temp);
}

/**
 * binary_tree_levelorder - goes through a binary tree using level-order
 * traversal
 * @tree: pointer to the root node of the tree to traverse
 * @func: pointer to a function to call for each node.
 */
void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
	queue_t *head, *tail = NULL;

	if (!tree || !func)
		return;
	head = queue_push(&tail, (binary_tree_t *)tree);
	while (head != NULL)
	{
		func(head->node->n);
		if (head->node->left)
			queue_push(&tail, head->node->left);
		if (head->node->right)
			queue_push(&tail, head->node->right);
		queue_pop(&head);
	}
}
