#include "main.h"

/**
 * print_num - prints integer
 * @n: number to print
 * Return: number of byte
 */

int print_num(unsigned int n)
{
	int count = 0, num_byte, x;
	unsigned int temp = n;
	char *arr;

	if (n == 0)
	{
		write(STDERR_FILENO, "0", 1);
		return (1);
	}
	while (temp > 0)
	{
		temp /= 10;
		count++;
	}
	arr = malloc(count + 1);
	if (arr == NULL)
	{
		perror("Allocation failed");
		exit(EXIT_FAILURE);
	}

	x = count - 1;
	while (n > 0)
	{
		arr[x--] = '0' + (n % 10);
		n /= 10;
	}
	num_byte = write(STDERR_FILENO, arr, count);
	free(arr);

	return (num_byte);
}

/**
 * print_err - prints error message
 * @cmd_num: command number
 * @prog_name: program name
 */

void print_err(int cmd_num, char *prog_name)
{
	_putstr(prog_name, STDERR_FILENO);
	_putstr(": ", STDERR_FILENO);
	print_num(cmd_num);
	_putstr(": ", STDERR_FILENO);
}
