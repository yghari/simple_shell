#include "shell.h"
/**
 * free_path - Frees memory allocated for path, input, and command arguments
 * @path: The path string
 * @input: The input string
 * @str: The array of command arguments
 *
 * Return: -1
 */
int free_path (char *path, char *input, char **str)
{
	free(path);
	free(input);
	free_buff(str);
	return (-1);
}
