#include "shell.h"
/**
 * prompt - Displays the shell prompt
 * @intrctv: Flag indicating whether the shell is interactive
 * Return: prompt
 */
void prompt(bool intrctv)
{
	if ((isatty(STDIN_FILENO) == 1) && (isatty(STDOUT_FILENO) == 1))
		intrctv = 1;
	if (intrctv)
		write(STDERR_FILENO, "$ ", 2);
}

/**
 * main - Entry point of the shell program
 * @ac: Number of command-line arguments
 * @av: Array of command-line arguments
 * @env: Array of environment variables
 * Return: 0 on success, -1 on error
 */
int main(int ac, char **av, char **env)
{
	t_flags flag;
	size_t buff = 0;
	ssize_t s_read = 0;
	int pokemon = 1;
	char *str = NULL;
	char **do_str = NULL;

	flag.intrctv = 0;
	(void)av, (void)env;
	if (ac < 1)
		return (-1);
	signal(SIGINT, handle_signal);
	while (pokemon)
	{
		prompt(flag.intrctv);
		fflush(stdout);
		s_read = getline(&str, &buff, stdin);
		if (s_read == EOF)
			break;
		flag.count++;
		if (*str == '\n')
		{
			free(str);
			str = NULL;
			continue;
		}
		do_str = parse(str, DELIMITER2);
		if (do_str[0] == NULL || handle_builtins(do_str) == 0)
		{
			free(str);
			str = NULL;
			continue;
		}
		else
			magic(str, s_read, do_str);
	}
	if (s_read < 0 && flag.intrctv)
		write(STDERR_FILENO, "\n", 1);
	free(str);
	return (0);
}
