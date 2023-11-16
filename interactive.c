#include "main.h"

/**
 * interactive - shell in interactive mode
 * Return: void
 */

void interactive(void)
{
	char *buff;
	char **argv;
	int status = -1;


	do {
		write(STDOUT_FILENO, prompt, 2);

		buff = get_input();
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
