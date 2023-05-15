#include "shell.h"

int prompt(void)
{
  char *prompt = "(Bstshell) $ ";
  int n = 0;
  
  n = write(STDOUT_FILENO, prompt, _strlen(prompt));
  return (0);
}


int main(int ac, char **av, char **env)
{
  size_t buff = 0;
  ssize_t s_read;
  int pokemon = 1;
  char *str = NULL, *path_cmd = NULL, *g_path = NULL;
  char **d_str = NULL, **paths = NULL;

  while (pokemon)
  {
    free_buff(d_str);
    free_buff(paths);
    prompt();
    fflush(stdout);
    if ((s_read = getline(&str, &buff, stdin)) == EOF) 
    {
        printf("\n");
        printf("exit\n");
        return (-1);
    }
    // if (s_read < 0)
    // {
      // if (s_read == EOF)
      // {
      //   perror("exit");
      //   exit;
      // }
      // printf("%s:Bad file descriptor\n", av[0]);
      // break;
    // }
    if (str[s_read - 1] == '\n')
      str[s_read - 1] = '\0';
    d_str = parse(str);
    if (d_str == NULL || *d_str == NULL || **d_str == '\0')
      continue;
    g_path = bring_path("PATH");
    paths = pathing(g_path);
    path_cmd = check_path(paths, d_str[0]);
    if (strcmp(d_str[0], "exit") == 0)
    {
      free(str);
      free_buff(d_str);
      break;
    }
    if (!path_cmd)
      perror("problem");
    else
      execution(d_str, path_cmd);
    for (int i = 0; d_str[i] != NULL; i++)
        printf("\nd_str[%d]: %s\n", i, d_str[i]);
  }
  return (0);
}
