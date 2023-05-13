#include "shell.h"

void    prompt(void)
{
  char *prompt = "(Bstshell) $ ";

  printf("%s", prompt);
}
char **parse(char *str)
{
  char **args = malloc(2 * sizeof(char *));
  int a_i = 0;
  char *to_ken;
  to_ken = strtok(str, " \t\n");
  while (to_ken != NULL)
  {
    args[a_i] = strdup(to_ken);
    a_i++;
    args = realloc(args, (a_i + 1) * sizeof(char *));
    to_ken = strtok(NULL, " \t\n");
  }
  args[a_i] = NULL;
  return args;
}
char  *bring_path(const char *path)
{
  int s_path = strlen(path);
  char **c_pa;

  for (c_pa = environ; *c_pa != NULL ; c_pa++)
  {
    if (strncmp(path, *c_pa, s_path) == 0 && *(*c_pa + s_path) == '=')
    {
      return (*c_pa + s_path + 1);
    }
  }
  return (NULL);
}

char **pathing(char *str)
{
  char **paths = malloc(2 * sizeof(char *));
  int i = 0;
  char *path;
  path = strtok(str, ":");
  while (path != NULL)
  {
    paths[i] = strdup(path);
    i++;
    paths = realloc(paths, (i + 1) * sizeof(char *));
    path = strtok(NULL, ":");
  }
  paths[i] = NULL;
  return paths;
}

char *_strcat(char *dest, char *src)
{
  char *hold;
	int i;
	int j;

	i = 0;
	j = 0;
  hold = malloc(sizeof(char *) * (strlen(dest) + strlen(src) + 2));
	while (dest[i])
  {
    hold[i] = dest[i];
		i++;
  }
  hold[i] = '/';
  i++;
  while (src[j])
	{
		hold[i] = src[j];
		i++;
		j++;
	}
	hold[i + 1] = '\0';
  printf("hold >> %s\n",hold);
	return (hold);
}

char  *check_path(char **paths, char **input)
{
  int i;
  char *path_cmd;

  i = 0;
  while (paths[i])
  {
    path_cmd = _strcat(paths[i], input[0]);
    i++;
  }
  return (NULL);
}
void  execution(char **input)
{
  pid_t pid ;
  int  status;
  char **paths;
  char *g_path;
  int i;
  char *test;
  
  g_path = bring_path("PATH");
  paths = pathing(g_path);
  test = check_path(paths, input);
  printf("%s\n", paths[0]);
  pid = fork();
  if (pid == 0)
  {
    execvp(g_path ,input);
    printf("done\n");
  }
  else if (pid < 0)
  {
    printf("error");
  }
  else
    wait(&status);
}

int main(int ac, char **av, char **env)
{
  char *str = NULL;
  size_t buff = 0;
  ssize_t s_read;
  char **d_str;

  while (1)
  {
    prompt();
    s_read = getline(&str, &buff, stdin);
    if (s_read < 0)
    {
      printf("\n%s: getline error\n", av[0]);
      break;
    }
    if (str[s_read - 1] == '\n')
      str[s_read - 1] = '\0';
    d_str = parse(str);
    printf("d_str[0]: %s\n", d_str[0]);
    if (strcmp(d_str[0], "exit") == 0)
    {
      free(str);
      free(d_str[0]);
      free(d_str);
      break;
    }
    execution(d_str);
    for (int i = 0; d_str[i] != NULL; i++)
      printf("d_str[%d]: %s\n", i, d_str[i]);
    free(d_str[0]);
    free(d_str);
  }
  return 0;
}
