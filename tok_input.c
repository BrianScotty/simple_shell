#include "main.h"

/**
 * tokenize_input - tokenizes input
 * @buff: pointer to input string
 * Return: pointer to token at index 0
 */

char **tokenize_input(char *buff)
{
	int buff_size = 64;
	int count = 0;
	char **tokens;
	char *token;
	const char *delim = " \n";

	tokens = malloc(buff_size * sizeof(char *));

	if (tokens == NULL)
	{
		perror("tsh: memory allocation error\n");
		exit(EXIT_FAILURE);
	}
	token = strtok(buff, delim);
	while (token != NULL)
	{

		if (token[0] == '#')
			break;
		tokens[count] = token;
		count++;

		if (count >= buff_size)
		{
			buff_size += buff_size;
			tokens = realloc(tokens, buff_size * sizeof(char));
			if (tokens == NULL)
			{
				perror("reallocation failed");
				exit(EXIT_FAILURE);
			}
		}
		token = strtok(NULL, delim);
	}
	tokens[count] = NULL;
	return (tokens);

}
