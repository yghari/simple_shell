#include "shell.h"

int magic(char *input, ssize_t size, char **d_str)
{
  char *path_cmd = NULL, *g_path = NULL;
  char **paths = NULL;
  int exit_code = 0;

  if (input[size - 1] == '\n')
      input[size - 1] = '\0'; 

  if (d_str == NULL || *d_str == NULL || **d_str == '\0')
  {
    free(input);
    free_buff(d_str);
    return (0);
  }
  g_path = _strdup(bring_path("PATH"));
  if (!g_path)
  {
    free(g_path);
    return (-1);
  }
  paths = parse(g_path, DELIMITER1);
  if (!paths)
  {
    free(g_path);
    free(input);
    free_buff(d_str);
    return (-1);
  }
  path_cmd = check_path(paths, d_str[0]);
  free_buff(paths);
  //free(input);
  if (!path_cmd)
  {
    free_buff(d_str);
    //free_buff(paths);
    free(g_path);
    printf(" \n error : command not found \n");
    return (-1);
  }
  else if (exit_code == 0)
  {
    exit_code = execution(d_str, path_cmd);
    free_buff(d_str);
    //free_buff(paths);
    free(g_path);
    free(path_cmd);
    return (0);
  }
  //free(path_cmd);
  for (int i = 0; d_str[i] != NULL; i++)
        printf("\nd_str[%d]: %s\n", i, d_str[i]);
}