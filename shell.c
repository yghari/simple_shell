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
 * process_commands - Process and execute individual commands
 * @str: The input string containing multiple commands
 * @s_read: The size of the input string
 */
void process_commands(char *str, ssize_t s_read)
{
	char **do_str = NULL, **commands;
	int i = 0;

	commands = parse(str, ";");
	while (commands[i] != NULL)
	{
		do_str = parse(commands[i], DELIMITER2);
		if (do_str[0] == NULL || handle_builtins(do_str, str) == 0)
		{
			i++;
			continue;
		}
		else
			magic(commands[i], s_read, do_str);
		i++;
	}
	free(commands);
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

		process_commands(str, s_read);

		free(str);
		str = NULL;
	}

	if (s_read < 0 && flag.intrctv)
		write(STDERR_FILENO, "\n", 1);

	free(str);
	return (0);
}
