#include "shell.h"
/**
 * exit_status - Manages the exit status of the shell
 * @update: Flag indicating whether to update the exit status
 * @n_status: New exit status value
 *
 * Return: Current exit status
 */
int exit_status(int update, int n_status)
{
	static int prev_status;

	if (update == 1)
		prev_status = n_status;
	return (prev_status);
}
