#include "shell.h"
/**
 * check_path - Checks if the command executable exists in the specified paths
 * @paths: The array of paths to search in
 * @input: The command to check for
 *
 * Return: The full path to the command executable if found, otherwise NULL
 */
char *check_path(char **paths, char *input)
{
	char *path_cmd = NULL;
	int i;

	if (access(input, F_OK | X_OK) == 0)
		return (_strdup(input));

	for (i = 0; paths[i] != NULL; i++)
	{
		path_cmd = _strcat(paths[i], input);

		if (access(path_cmd, F_OK | X_OK) == 0)
		{
			return (path_cmd);
		}
	}
	return (NULL);
}
