#include "monty.h"

/**
 * op_push - pushes an element onto the stack.
 * @stack: Pointer to the stack
 * @line_number: The current line number in the Monty bytecode file
 *
 * Description: This function pushes an integer element onto the stack.
 * Return: (_void_)
 */
void op_push(stack_t **stack, unsigned int line_number)
{
	stack_t *new_node;
	char *argument;
	int push_value;

	/* Get the integer value from the command argument */
	argument = strtok(NULL, "\n \t");

	/* Check if the argument is a valid integer */
	if (!is_integer(argument))
	{
		fprintf(stdout, "L%u: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}

	push_value = atoi(argument);

	/* Allocate memory for the new node */
	new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
	{
		fprintf(stdout, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	new_node->n = push_value;
	new_node->prev = NULL;
	new_node->next = *stack;

	/* Check if the stack is empty */
	if (*stack != NULL)
	{
		(*stack)->prev = new_node;
	}
	*stack = new_node;
}

/**
 * op_pall - Print all values on the stack.
 * @stack: Pointer to the stack
 * @line_number: Current line number in the Monty bytecode file
 *
 * Description: This function prints all values on the stack
 *	starting from the top of the stack and moving towards the bottom.
 * Return: (_void_)
 */
void op_pall(stack_t **stack, unsigned int line_number)
{
	stack_t *current_node = *stack;

	/* Anticipate/remove unused parameter warning */
	UNUSED(line_number);

	while (current_node != NULL)
	{
		printf("%d\n", current_node->n);
		current_node = current_node->next;
	}
}

/**
 * op_pint - Print the value at the top of the stack + endline
 * @stack: Pointer to the stack
 * @line_number: Current line number in the Monty bytecode file
 *
 * Description: This function checks the stack
 *	and prints the value at its top.
 * Return: (_void_)
 */
void op_pint(stack_t **stack, unsigned int line_number)
{
	stack_t *top_node = *stack;

	/* Print error if stack is empty */
	if (*stack == NULL)
	{
		fprintf(stdout, "L%d: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", top_node->n);
}

/**
 * op_pop - Remove the value at the top of the stack
 * @stack: Pointer to the stack
 * @line_number: Current line number in the Monty bytecode file
 *
 * Description: This function checks the stack
 *	and frees the value at its top.
 * Return: (_void_)
 */
void op_pop(stack_t **stack, unsigned int line_number)
{
	stack_t *top_node;

	if (*stack == NULL)
	{
		fprintf(stdout, "L%d: can't pop an empty stack\n", line_number);
		exit(EXIT_FAILURE);
	}

	top_node = *stack;
	*stack = (*stack)->next;
	free(top_node);
}
