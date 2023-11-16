#include "main.h"

/**
 * main - shell entry point
 * Return: 0 (success)
 */

int main(void)
{
	if (isatty(STDIN_FILENO) == 1)
	{
		interactive();
	}
	else
	{
		non_interactive();
	}
	return (0);
}
