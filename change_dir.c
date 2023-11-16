#include "main.h"

/**
 * func_cd - changes working directory
 * @argv: target directory
 * Return: 1 (success), 0 (failure)
 */

int func_cd(char **argv)
{
	if (argv[1] == NULL)
	{
		perror("chdir");
	}
	else
	{
		if (chdir(argv[1]) != 0)
		{
			perror("error in chdir..\n");
			return (-1);
		}
	}
	return (-1);
}
