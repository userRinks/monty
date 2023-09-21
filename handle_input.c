#define _POSIX_C_SOURCE 200809L /* for getline */
#include "monty.h"

/**
 * open_and_validate_file - Open and validate the Monty bytecode file
 * @file_path: Path to the Monty bytecode file
 * Return: Valid file pointer or NULL on failure
 */
FILE *open_and_validate_file(char *file_path)
{
	FILE *my_input = fopen(file_path, "r");

	if (my_input == NULL)
	{
		fprintf(stdout, "Error: Can't open file %s\n", file_path);
		exit(EXIT_FAILURE);
	}

	return (my_input);
}

/**
 * process_file - Process the Monty bytecode file line by line
 * @my_input: Valid file pointer
 */
void process_file(FILE *my_input)
{
	char *line = NULL;
	size_t getline_size = 0;
	unsigned int line_number = 0;
	stack_t *top = NULL;
	instruction_t *instruction = NULL;

	while (getline(&line, &getline_size, my_input) != -1)
	{
		line_number++;
		instruction = parse_line(line);

		if (skip_line(instruction, &line))
			continue;

		if (execute_instruction(instruction, &top, line_number))
		{
			fprintf(stdout, "L%d: unknown instruction %s\n",
					line_number, instruction->opcode);
			free(instruction);
			free_stack(top);
			fclose(my_input);
			free(line);
			exit(EXIT_FAILURE);
		}

		free(instruction);
	}

	free(line);
	free_stack(top);
}

/**
 * skip_line - Skip comments and empty lines
 * @instruction: Parsed instruction
 * @line: Current line
 * Return: 1 if the line should be skipped, 0 otherwise
 */
int skip_line(instruction_t *instruction, char **line)
{
	if (!instruction->opcode || instruction->opcode[0] == '#')
	{
		/* free(instruction); */
		free(*line);
		*line = NULL;
		return (1);
	}
	return (0);
}

/**
 * execute_instruction - Execute the Monty instruction
 * @instruction: Parsed instruction
 * @top: Pointer to the top of the stack
 * @line_number: Current line number
 * Return: 1 if an unknown instruction, 0 otherwise
 */
int execute_instruction(instruction_t *instruction,
		stack_t **top, unsigned int line_number)
{
	if (instruction->f)
	{
		instruction->f(top, line_number);
		return (0);
	}
	return (1);
}

/**
 * handle_unknown_instruction - Handle unknown instructions
 * @instruction: Parsed instruction
 * @line_number: Current line number
 * @my_input: File pointer
 * @top: Pointer to the top of the stack
 */
void handle_unknown_instruction(instruction_t *instruction,
		unsigned int line_number, FILE *my_input, stack_t *top)
{
	fprintf(stdout, "L%d: unknown instruction %s\n",
			line_number, instruction->opcode);
	free(instruction);
	free_stack(top);
	fclose(my_input);
	exit(EXIT_FAILURE);
}
