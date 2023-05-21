#include "shell.h"

int prompt(bool intrctv)
{
	if ((isatty(STDIN_FILENO) == 1) && (isatty(STDOUT_FILENO) == 1))
		intrctv = 1;
	if (intrctv)
		write(STDERR_FILENO, "$ ", 2);
}

int main(int ac, char **av, char **env)
{
  (void)av, (void)env;
  size_t buff = 0;
  t_flags flag;
  ssize_t s_read = 0, exit_code = 0;;
  int pokemon = 1;
  char *str = NULL;
  char **do_str = NULL;

  if (ac < 1)
		return (-1);
	signal(SIGINT, handle_signal);
  while (pokemon)
  {
    prompt(flag.intrctv);
    fflush(stdout);
    if ((s_read = getline(&str, &buff, stdin)) == EOF) 
    {
      break;
    }
    flag.count++;
    do_str = parse(str, DELIMITER2);
    if (handle_builtins(do_str) == 0)
      continue;
    else
      magic(str, s_read, do_str);
  }
  if (s_read < 0 && flag.intrctv)
		write(STDERR_FILENO, "\n", 1);
  free(str);
  return (0);
}
