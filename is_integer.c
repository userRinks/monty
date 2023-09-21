#include "monty.h"

/**
 * is_integer - checks if a string represents a valid integer
 * @str: the string to check
 *
 * Return: 1 if the string represents a valid integer, 0 otherwise
 */

int is_integer(char *str)
{
	int i = 0;

	if (str == NULL || *str == '\0')
		return (0);

	/* Skip the optional negative sign */
	if (str[i] == '-')
		i++;

	for (; str[i] != '\0'; i++)
	{
		/* Non-digit character found */
		if (!isdigit(str[i]))
			return (0);
	}

	/* Empty string / All characters are digits */
	return (1);
}
