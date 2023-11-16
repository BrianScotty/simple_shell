#include "main.h"

/**
 * get_input - reads input from user
 * Return: pointer to read input
 */

char *get_input(void)
{
	char *lineptr = NULL;
	size_t n = 0;
	ssize_t get_line;

	get_line = getline(&lineptr, &n, stdin);

	if (get_line == -1)
	{
		free(lineptr);
		exit(EXIT_FAILURE);
	}
	return (lineptr);
}
