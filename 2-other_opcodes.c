#include "monty.h"

/**
 * op_swap - Swap the first two elements in the stack
 * @stack: Pointer to the stack
 * @line_number: Current line number in the Monty bytecode file
 *
 * Description: This function checks the stack
 *	and exchanges the values of the two elements at the top.
 * Return: (_void_)
 */
void op_swap(stack_t **stack, unsigned int line_number)
{
	int swap_me;

	if ((*stack) == NULL)
	{
		fprintf(stdout, "L%d: can't swap, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	if ((*stack)->next == NULL)
	{
		fprintf(stdout, "L%d: can't swap, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	swap_me = (*stack)->n;
	(*stack)->n = (*stack)->next->n;
	(*stack)->next->n = swap_me;
}

/**
 * op_nop - ¯\_(ツ)_/¯
 *@stack: Pointer to the stack
 * @line_number: Current line number in the Monty bytecode file
 *
 * Description: The nop opcode literally does nothing
 * Return: (_void_)
 */
void op_nop(stack_t **stack, unsigned int line_number)
{
	/* Anticipate unused value flags */
	UNUSED(stack);
	UNUSED(line_number);
}
