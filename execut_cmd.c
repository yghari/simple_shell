#include "shell.h"

int execution(char **input, char *test)
{
  pid_t pid;
  int status;
  char **env = environ;

  pid = fork();
  if (pid == -1) 
  {
    perror("fork");
    return (0);
  }
  else if (pid == 0) 
  {
    execve(test, input, env);
  }
  else 
    wait(&status);
  return (1);
}
