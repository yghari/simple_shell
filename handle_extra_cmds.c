#include "shell.h"

int handle_builtins(char **d_str)
{
  if (strcmp(d_str[0], "exit") == 0)
  {
    free_buff(d_str);
    //free_buff(paths);
    exit (0);
  }
  else if (strcmp(d_str[0], "cd") == 0)
  {
    //free(input);
    cd_cmd(d_str);
  }
}