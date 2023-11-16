#include "main.h"

/**
 * str_len - gets length of a string
 * @str: string to check
 * Return: string length
 */

int str_len(char *str)
{
	int length = 0;

	while (str[length] != '\0')
		length++;
	return (length);
}

/**
 * str_dup - duplicates a string
 * @s: string to duplicate
 * Return: duplicated string
 */

char *str_dup(char *s)
{
	char *str_cpy;
	int length = 0, x;

	if (s == NULL)
		return (NULL);

	length = str_len(s) + 1;

	str_cpy = malloc(sizeof(*str_cpy) * length);

	if (str_cpy == NULL)
	{
		return (NULL);
	}

	for (x = 0; x < length; x++)
		str_cpy[x] = s[x];

	return (str_cpy);
}

/**
 * str_cat - links two string
 * @dest: pointer to linked string
 * @src: pointer to strings to link
 * Return: linked string
 */

char *str_cat(char *dest, char *src)
{
	int m = 0;
	int n = 0;

	while (dest[m] != '\0')
	{
		m++;
	}
	while (src[n] != '\0')
	{
		dest[m + n] = src[n];
		n++;
	}
	dest[m + n] = '\0';
	return (dest);
}

/**
 * str_cpy - copies a string
 * @dest: pointer to new string
 * @src: pointer to old string
 * Return: Copied string
 */

char *str_cpy(char *dest, char *src)
{
	int i = 0;

	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}
