#include "shell.h"

int prompt(void)
{
  char *prompt = "(Bstshell) $ ";
  int n = 0;
  
  n = write(STDOUT_FILENO, prompt, _strlen(prompt));
  return (0);
}

int magic(char *input, ssize_t size)
{
  char *path_cmd = NULL, *g_path = NULL;
  char **d_str = NULL, **paths = NULL;
  int exit_code;

  free_buff(paths);
  free_buff(d_str);

  if (input[size - 1] == '\n')
      input[size - 1] = '\0'; 
  d_str = parse(input);
  if (d_str == NULL || *d_str == NULL || **d_str == '\0')
  {
    free_buff(d_str);
    return (0);
  }
  if (strcmp(d_str[0], "exit") == 0)
  {
    free(input);
    free_buff(d_str);
    free_buff(paths);
    return (-1);
  }
  g_path = bring_path("PATH");
  if (g_path == NULL)
  {
    free(g_path);
    return (-1);
  }
  paths = pathing(g_path);
  path_cmd = check_path(paths, d_str[0]);
  if (!path_cmd)
  {
    perror("problem");
  }
  else
      exit_code = execution(d_str, path_cmd);
  free(path_cmd);
  for (int i = 0; d_str[i] != NULL; i++)
        printf("\nd_str[%d]: %s\n", i, d_str[i]);
  return (exit_code);

}
int main(int ac, char **av, char **env)
{
  size_t buff = 0;
  ssize_t s_read = 0;
  int pokemon = 1;
  char *str = NULL;
  int exit_code = 0;

  while (pokemon)
  {
    
    prompt();
    fflush(stdout);
    if ((s_read = getline(&str, &buff, stdin)) == EOF) 
    {
      free(str);
      printf("\n");
      printf("exit\n");
      return (-1);
    }
    if (str[s_read - 1] == '\n')
      str[s_read - 1] = '\0'; 
    exit_code = magic(str, s_read);
    if (exit_code == -1)
    {
      //free(str);
      printf("exit\n");
      return (-1);
    }
  }
  free(str);
  return (0);
}
