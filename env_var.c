#include "main.h"

/**
 * func_env - prints enviroment variables
 * @argv: arguments
 * Return: 1 (success), 0 (failure)
 */

int func_env(char **argv)
{
	int i = 0;
	(void)(**argv);

	while (environ[i])
	{
		write(STDOUT_FILENO, environ[i], str_len(environ[i]));
		write(STDOUT_FILENO, "\n", 1);
		i++;
	}
	return (-1);
}
