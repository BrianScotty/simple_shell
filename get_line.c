#include "main.h"

/**
 * get_line - read a line from the stream
 * Return: pointer to the line
 */

char *get_line(void)
{
	int buf_size = 1024;
	int k = 0;
	char *line_buff = malloc(sizeof(char) * buf_size);
	int linechar;

	if (line_buff == NULL)
	{
		fprintf(stderr, "allocation error in read_stream");
		exit(EXIT_FAILURE);
	}
	while (1)
	{
		linechar = getchar();
		if (linechar == EOF)
		{
			free(line_buff);
			exit(EXIT_SUCCESS);
		}
		else if (linechar == '\n')
		{
			line_buff[k] = '\0';
			return (line_buff);
		}
		else
		{
			line_buff[k] = linechar;
		}
		k++;
		if (k >= buf_size)
		{
			buf_size += buf_size;
			line_buff = realloc(line_buff, buf_size);
			if (line_buff == NULL)
			{
				fprintf(stderr, "reallocation error in read_stream");
				exit(EXIT_FAILURE);
			}
		}
	}
}
