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
 * free_queue - empties the queue
 * @head: pointer to the front of the queue
 */
void free_queue(queue_t *head)
{
	queue_t *temp;

	while (head)
	{
		temp = head->next;
		free(head);
		head = temp;
	}
}

/**
 * binary_tree_is_heap - checks if a binary tree is a valid Max Binary Heap
 * @tree: pointer to the root node of the tree to check
 *
 * Return: 1 if tree is a valid Max Binary Heap, and 0 otherwise
 */
int binary_tree_is_heap(const binary_tree_t *tree)
{
	int flag = 0;
	queue_t *head, *tail = NULL;
	binary_tree_t *parent;

	if (!tree)
		return (0);
	head = queue_push(&tail, (binary_tree_t *)tree);
	while (head)
	{
		parent = head->node->parent;
		if (parent && parent->n < head->node->n)
		{
			free_queue(head);
			return (0);
		}
		if (head->node->left)
		{
			if (flag)
			{
				free_queue(head);
				return (0);
			}
			queue_push(&tail, head->node->left);
		}
		else
			flag = 1;
		if (head->node->right)
		{
			if (flag)
			{
				free_queue(head);
				return (0);
			}
			queue_push(&tail, head->node->right);
		}
		else
			flag = 1;
		queue_pop(&head);
	}
	return (1);
}
