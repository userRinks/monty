#include "monty.h"

/**
 * op_add - Add the initial two elements in the stack
 * @stack: Pointer to the stack
 * @line_number: Current line number in the Monty bytecode file
 *
 * Description: This function adds the top two elements in the stack
 *	and overwrites the result to the top.
 * Return: (_void_)
 */
void op_add(stack_t **stack, unsigned int line_number)
{
	int result;

	if  ((*stack) == NULL || (*stack)->next == NULL)
	{
		fprintf(stdout, "L%d: can't add, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	/* Add the elements, save the result */
	result = (*stack)->next->n + (*stack)->n;

	/* pop out(delete)the operands */
	op_pop(stack, line_number);

	/* Save the result to the top stack */
	(*stack)->n = result;
}

