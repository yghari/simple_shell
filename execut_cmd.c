#include "shell.h"
/**
 * execution - Executes a command with the given arguments
 * @input: The array of command arguments
 * @test: The path to the command executable
 *
 * Return: 1 on successful execution, 0 on failure
 */
int execution(char **input, char *test)
{
	pid_t pid;
	int status;
	char **env = environ;

	pid = fork();
	if (pid == -1)
	{
		perror("fork");
		return (0);
	}
	else if (pid == 0)
	{
		execve(test, input, env);
		perror("execve");
		if (errno == EACCES)
			exit(126);
		exit(errno);
	}
	else
	{
		wait(&status);
		if (WIFEXITED(status))
			exit_status(1, WEXITSTATUS(status));
		else
			exit_status(1, 1);
	}

	return (1);
}
