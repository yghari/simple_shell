#include "shell.h"
/**
 * handle_builtins - Handles built-in commands in the shell
 * @d_str: The array of command arguments
 *
 * Return: 1 if the command is not a built-in, 0 if it is a built-in
 */
int handle_builtins(char **d_str)
{
	t_builti cmd = {"exit", "cd", "env"};

	if (strcmp(d_str[0], cmd.exit) == 0)
	{
		free_buff(d_str);
		_fprint(1, "exit\n");
		exit(exit_status(0, 0));
	}
	else if (strcmp(d_str[0], cmd.c_d) == 0)
	{
		cd_cmd(d_str);
		return (0);
	}
	else if (strcmp(d_str[0], cmd.en_v) == 0)
	{
		env_cmd();
		return (0);
	}
	return (exit_status(1, 1));
}
