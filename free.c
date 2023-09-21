#include "monty.h"

/**
 * free_stack - Free the list
 * @current_node: pointer to current head of list
 *
 * Description: Checks list and frees elements
 * Return: (_void_)
 */

void free_stack(stack_t *current_node)
{
	stack_t *next_node;

	/* If list is free, stop executing */
	if (!current_node)
		return;

	/* Move step by step freeing elements */
	next_node = current_node;

	while (next_node)
	{
		current_node = next_node;
		next_node = current_node->next;
		free(current_node);
	}
}
