#include "main.h"

/**
 * execute_cmd - executes a command
 * @argv: command to execute
 * @cmd_num: comand number
 * Return: 1 (success), else 0
 */

int execute_cmd(char **argv, int cmd_num)
{
	pid_t child_pid;
	int x, status;
	char *cmd, *a,  *prog_name = "./hsh";

	if (argv != NULL)
	{
		cmd = argv[0];
		a = get_path(cmd);
		if (a == NULL)
		{
			print_err(cmd_num, prog_name);
			_putstr(argv[0], STDERR_FILENO);
			_putstr(": not found\n", STDERR_FILENO);
			return (127);
		}
		child_pid = fork();
		if (child_pid == 0)
		{
			x = execve(a, argv, environ);
			if (x == -1)
			{
				print_err(cmd_num, prog_name);
				_putstr(strerror(errno), STDERR_FILENO);
				write(STDERR_FILENO, strerror(errno), str_len(strerror(errno)));
			}
		}
		else if (child_pid < 0)
			perror("fork failed");
		else
		{
			do {
				waitpid(child_pid, &status, WUNTRACED);
			} while (!WIFEXITED(status) && !WIFSIGNALED(status));
		}
		if (a != cmd)
			free(a);
		return (-1);
	}
	return (0);
}
