#include "shell.h"
/**
 * free_buff - Frees memory allocated for a buffer of strings
 * @buf: The buffer of strings
 */
void free_buff(char **buf)
{
	int i = 0;

	if (buf == NULL)
		return;
	while (buf[i])
	{
		free(buf[i]);
		buf[i] = NULL;
		i++;
	}
	free(buf);
}
