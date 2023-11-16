#include "main.h"

/**
 * exe_input - executes executable input
 * @argv: input to execute
 * Return: executed command
 */

int exe_input(char **argv)
{
	static int arg_num;
	char *builtin_funcs[] = {"env", "cd", "exit",};

	int (*builtin_func[])(char **) = {&func_env, &func_cd, &func_exit, NULL};

	size_t x = 0;

	if (argv[0] == NULL)
	{
		return (-1);
	}

	for (; x < sizeof(builtin_funcs) / sizeof(char *); x++)
	{
		if (str_cmp(argv[0], builtin_funcs[x]) == 0)
		{
			return ((*builtin_func[x])(argv));
		}
	}

	arg_num++;
	return (execute_cmd(argv, arg_num));
}
