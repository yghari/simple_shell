#include "shell.h"

int	main(int ac, char **av, char **env)
{
  char *line = NULL;
  size_t len = 0;
  ssize_t read;

  while (1)
  {
    read = getline("$_> ");
  }
  return (0);
}