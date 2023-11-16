#include "main.h"

/**
 * non_interactive - shell in non-interactive mode execution
 * Return: void
 */

void non_interactive(void)
{
	char *buff;
	char **argv;
	int status = -1;

	do {
		buff = get_line();
		argv = tokenize_input(buff);
		status = exe_input(argv);

		free(buff);
		free(argv);

		if (status >= 0)
		{
		exit(status);
		}
	} while (status == -1);
}
