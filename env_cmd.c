#include "shell.h"

void env_cmd(void)
{
  char **env = environ;

  while(*env)
  {
    printf("%s\n", *env++);
  }
}