#include "monty.h"

/**
 * main - Run monty program
 * @argc: argument count
 * @argv: argument vector
 * Return: exit code
 */

int main(int argc, char **argv)
{
	FILE *my_input;

	if (check_argument_count(argc))
		return (EXIT_FAILURE);

	my_input = open_and_validate_file(argv[1]);
	process_file(my_input);

	return (EXIT_SUCCESS);
}

/**
 * check_argument_count - Check the number of command-line arguments
 * @argc: Argument count
 * Return: 0 if argc is correct, 1 if otherwise
 */
int check_argument_count(int argc)
{
	if (argc != 2)
	{
		fprintf(stdout, "USAGE: monty file\n");
		return (1);
	}
	return (0);
}
