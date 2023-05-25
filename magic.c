#include "shell.h"
/**
 * magic - Executes a command with the appropriate path
 * @input: The input command string
 * @size: The size of the input string
 * @d_str: Array of parsed command arguments
 * Return: 0 on success, -1 on error
 */
int magic(char *input, ssize_t size, char **d_str)
{
	char *path_cmd = NULL, *g_path = NULL;
	char **paths = NULL;
	int exit_code = 0;

	if (input[size - 1] == '\n')
		input[size - 1] = '\0';

	if (d_str == NULL || *d_str == NULL || **d_str == '\0')
	{
		free(input);
		free_buff(d_str);
		return (0);
	}
	g_path = _strdup(bring_path("PATH"));
	if (!g_path)
	{
		free(g_path);
		perror("Error: Failed to duplicate path");
		return (-1);
	}
	paths = parse(g_path, DELIMITER1);
	if (!paths)
		free_path(g_path, input, d_str);
	path_cmd = check_path(paths, d_str[0]);
	free_buff(paths);
	if (!path_cmd)
	{
		free_buff(d_str);
		free(g_path);
		free(path_cmd);
		perror("Error: Command not found");
		exit_status(1, 127);
		return (-1);
	}
	else if (exit_code == 0)
	{
		exit_code = execution(d_str, path_cmd);
		free_cmd(d_str, g_path, path_cmd);
	}
	return (exit_code);
}
