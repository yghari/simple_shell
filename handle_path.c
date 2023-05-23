#include "shell.h"
/**
 * bring_path - Retrieves the value of an environment variable
 * @path: The name of the environment variable
 *
 * Return: A pointer to the value of the environment variable,
 *         or NULL if the variable is not found
 */
char *bring_path(char *path)
{
	char **env;
	int path_len = _strlen(path);

	for (env = environ; *env != NULL; env++)
	{
		if (_strncmp(*env, path, path_len) == 0 && *(*env + path_len) == '=')
		{
			return (*env + path_len + 1);
		}
	}
	_putstring("path not found\n");
	return (NULL);
}
/**
 * length_of_paths - Calculates the number of paths in a string
 * @path: The string containing multiple paths
 * @del: The delimiter used to separate paths
 *
 * Return: The number of paths in the string
 */
int length_of_paths(char *path, char *del)
{
	int length;
	char *line, *copied_path;

	length = 0;
	copied_path = strdup(path);
	line = strtok(copied_path, del);
	while (line)
	{
		length++;
		line = strtok(NULL, del);
	}
	free(copied_path);
	return (length);
}
