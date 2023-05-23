#include "shell.h"
/**
 * free_path - Frees memory allocated for path, input, and command arguments
 * @path: The path string
 * @input: The input string
 * @str: The array of command arguments
 *
 * Return: -1
 */
int free_path(char *path, char *input, char **str)
{
	free(path);
	free(input);
	free_buff(str);
	return (-1);
}
/**
 * free_cmd - Frees memory allocated for command-related variables
 * @d_str: Array of parsed command arguments
 * @g_path: Path variable
 * @path_cmd: Command path
 *
 * Return: Always 0
 */
int free_cmd(char **d_str, char *g_path, char *path_cmd)
{
	free_buff(d_str);
	free(g_path);
	free(path_cmd);
	return (0);
}
