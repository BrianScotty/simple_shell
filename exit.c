#include "main.h"

/**
 *func_exit - ends a process
 *@argv: empty arguement array
 * Return: 0 (success)
 */

int func_exit(char **argv)
{
	if (argv[1])
	{
		return (atoi(argv[1]));
	}
	else
	{
		return (0);
	}
}
