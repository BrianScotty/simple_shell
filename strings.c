#include "main.h"

/**
 * _putchar - prints a character
 * @z: character to print
 * Return: printed character
 */

int _putchar(char z)
{
	return (write(1, &z, 1));
}

/**
 * _putstr - prints a string
 * @str: string to print
 * @fd: file descriptor
 * Return: number of strings printed
 */

int _putstr(char *str, int fd)
{
	int count = 0, m = 0;

	while (str[m] != '\0')
	{
		write(fd, &str[m], 1);
		count += 1;
		m++;
	}
	return (count);
}

/**
 * str_cmp - compares two strings
 * @s1: string 1
 * @s2: string 2
 * Return: 0 (success)
 */

int str_cmp(char *s1, char *s2)
{
	int k = 0;

	while (s1[k] != '\0' && s2[k] != '\0')
	{
		if (s1[k] != s2[k])
		{
			return (s1[k] - s2[k]);
		}
		k++;
	}
	return (0);
}
