#include "main.h"
/**
 * get_path - gets variable PATH
 * @args: command to locate
 * Return: the path
 */
char *get_path(char *args)
{
	char *delim = ":", *path, *cpy_path;
	char *pathTok, *fileName;
	struct stat argv_line;

	path = getenv("PATH");
	if (path != NULL)
	{
		cpy_path = str_dup(path);
		pathTok = strtok(cpy_path, delim);
		while (pathTok)
		{
			fileName = malloc(str_len(args) + str_len(pathTok) + 2);
			str_cpy(fileName, pathTok);
			str_cat(fileName, "/");
			str_cat(fileName, args);
			str_cat(fileName, "\0");

			if (stat(fileName, &argv_line) == 0)
			{
				free(cpy_path);
				return (fileName);
			}
			else
			{
				free(fileName);
				pathTok = strtok(NULL, delim);
			}
		}
		free(cpy_path);

		if (stat(args, &argv_line) == 0)
		{
			return (args);
		}
		return (NULL);
	}
	return (NULL);
}
