#include "shell.h"

int handle_builtins(char **d_str)
{
  t_builti cmd = {"exit" , "cd" , "env"};

  if (strcmp(d_str[0], cmd.exit) == 0)
  {
    free_buff(d_str);
    exit (0);
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
  // free_buff(d_str);
  return (1);
}