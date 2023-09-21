#include "monty.h"

/**
 * read_opcode - gets the opcode
 * @code: the line of code
 * Return: opcode
 */
char *read_opcode(char *code)
{
	char *opcode;

	/* Read first argument */
	opcode = strtok(code, "\n\t ");
	return (opcode);
}

/**
 * parse_line - Analyze line to return corresponding instruction
 * @line: Pointer to the line being parsed
 * Return: ptr to corresponding instruction
 */

instruction_t *parse_line(char *line)
{
	char *opcode;
	instruction_t *instruction;
	opcode = read_opcode(line);

	instruction = malloc(sizeof(*instruction));
	if (instruction == NULL)
	{
		fprintf(stdout, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}

	instruction->opcode = opcode;
	instruction->f = NULL;

	/* Interpreter */
	if (instruction->opcode)
	{
		if (strcmp(instruction->opcode, "push") == 0)
			instruction->f = op_push;
		if (strcmp(instruction->opcode, "pall") == 0)
			instruction->f = op_pall;
		if (strcmp(instruction->opcode, "pint") == 0)
			instruction->f = op_pint;
		if (strcmp(instruction->opcode, "pop") == 0)
			instruction->f = op_pop;
		if (strcmp(instruction->opcode, "swap") == 0)
			instruction->f = op_swap;
		if (strcmp(instruction->opcode, "add") == 0)
			instruction->f = op_add;
		if (strcmp(instruction->opcode, "nop") == 0)
			instruction->f = op_nop;
	}

	return (instruction);
}
