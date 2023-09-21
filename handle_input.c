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

		if (!(instruction->opcode) || instruction->opcode[0] == '#')
		{
			/* Skip comments and empty lines */
			free(instruction);
			if (line)
				free(line);
			line = NULL;
			continue;
		}

		if (instruction->f)
		{
			/* Execute the instruction function */
			instruction->f(&top, line_number);
		}
		else
		{
			/* Handle unknown instructions */
			fprintf(stdout, "L%d: unknown instruction %s\n",
					line_number, instruction->opcode);
			free(instruction);

			/* Clean up stack */
			if (line)
				free(line);
			free_stack(top);
			fclose(my_input);
			exit(EXIT_FAILURE);
		}

		/* Clean up parsed instruction and line */
		free(instruction);
		if (line)
			free(line);
		line = NULL;
	}

    /* Clean up resources and close the file */
	if (line)
		free(line);
	free_stack(top);
	fclose(my_input);
}
