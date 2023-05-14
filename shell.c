#include "shell.h"

void    prompt(void)
{
  char *prompt = "(Bstshell) $ ";

  printf("%s", prompt);
}

void free_buff(char **buf)
{
    int i = 0;

    if (buf == NULL)
        return;

    while (buf[i])
    {
        free(buf[i]);
        i++;
    }

    free(buf);
}

char **parse(char *str)
{
    int size = 2;
    char **args = malloc(size * sizeof(char *));
    int a_i = 0;
    char *to_ken;
    to_ken = strtok(str, " \t\n");
    while (to_ken != NULL)
    {
        args[a_i] = strdup(to_ken);
        a_i++;
        if (a_i == size) {
            size *= 2;
            args = realloc(args, size * sizeof(char *));
        }
        to_ken = strtok(NULL, " \t\n");
    }
    args[a_i] = NULL;
    return args;
}

char *bring_path(const char *path)
{
    int path_len = strlen(path);
    for (char **env = environ; *env != NULL; env++)
    {
        if (strncmp(*env, path, path_len) == 0 && *(*env + path_len) == '=') {
            return (*env + path_len + 1);
        }
    }
    printf("path not found\n");
  
    return NULL;
}

char **pathing(char *str)
{
    int size = 2;
    char **paths = NULL;
    paths = malloc(size * sizeof(char *));
    if (paths == NULL)
        return NULL;
    int i = 0;
    char *path;
    char *c_path;
    c_path = strdup(str);
    path = strtok(c_path, ":");
    while (path != NULL) {
        if (i == size - 1) {
            size *= 2;
            paths = realloc(paths, size * sizeof(char *));
            
            if (paths == NULL)
                return NULL;
        }

        paths[i] = strdup(path);
        if (paths[i] == NULL)
            return NULL;
        i++;
        path = strtok(NULL, ":");
    }
    paths[i] = NULL;
    return paths;
}

char *_strcat(char *dest, char *src)
{
    char *hold;
    int i = 0;
    int j = 0;

    hold = malloc(sizeof(char) * (strlen(dest) + strlen(src) + 2));
    if (hold == NULL)
        return NULL;
    while (dest[i]) {
        hold[i] = dest[i];
        i++;
    }
    hold[i] = '/';
    i++;
    while (src[j]) {
        hold[i] = src[j];
        i++;
        j++;
    }
    hold[i] = '\0';
    return hold;
}

char *check_path(char **paths, char *input)
{
    char *path_cmd = NULL;
    for (int i = 0; paths[i] != NULL; i++)
    {
        path_cmd = _strcat(paths[i], input);   
        if (access(path_cmd, F_OK | X_OK) == 0) 
        {
          return path_cmd;
        }
        free(path_cmd);
    }
    return NULL;
}

int execution(char **input, char *test)
{
  pid_t pid;
  int status;
  char **env = environ;

  pid = fork();
  if (pid == -1) 
  {
    perror("fork");
    return 0;
  }
  else if (pid == 0) 
  {
    // Child process
    execve(test, input, env);
    free(test);
    free_buff(input);
  }
  else 
    wait(&status);
  return 1;
}

int main(int ac, char **av, char **env)
{
  char *str , *test = NULL;
  size_t buff = 0;
  ssize_t s_read;
  char **d_str = NULL;
  char **paths = NULL;
  char *g_path = NULL;

  while (1)
  {
    free_buff(d_str);
    free_buff(paths);
    //free(test);
    prompt();
    s_read = getline(&str, &buff, stdin);
    if (s_read < 0)
    {
      printf("\n%s: getline error\n", av[0]);
      break;
    }
    if (str[s_read - 1] == '\n')
      str[s_read - 1] = '\0';
    g_path = bring_path("PATH");
    d_str = parse(str);
    for (int i = 0; d_str[i] != NULL; i++)
        printf("\nd_str[%d]: %s\n", i, d_str[i]);
    paths = pathing(g_path);
    test = check_path(paths, d_str[0]);
    if (strcmp(d_str[0], "exit") == 0)
    {
      free(str);
      free(d_str[0]);
      //d_str[0] = NULL; // set to NULL after freeing
      free_buff(d_str);
      break;
    }
    if (!test)
      perror("problem");
    else
      execution(d_str, test);
  }

  
  return 0;
}
