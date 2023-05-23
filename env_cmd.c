#include "shell.h"
/**
 * env_cmd - Prints the environment variables
 *
 * Description: This function prints the environment variables. It uses
 * the 'environ' variable, which is a global variable containing the
 * environment variables passed to the program. It iterates through the
 * environment variables using a while loop and prints each variable
 * using the printf() function. The loop terminates when it reaches the
 * end of the environment variables, which is indicated by a NULL pointer.
 */
void env_cmd(void)
{
	char **env = environ;

	while(*env)
	{
		printf("%s\n", *env++);
	}
}
