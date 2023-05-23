#include "shell.h"
/**
 * handle_signal - Handles signal interrupt (SIGINT)
 * @m: The signal number
 */
void handle_signal(int m)
{
	(void)m;
	write(STDERR_FILENO, "\n", 1);
	write(STDERR_FILENO, "$ ", 2);
}
