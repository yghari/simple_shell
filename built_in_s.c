#include "shell.h"

void  cd_cmd(char **input)
{
  char *current_dir = NULL;
  char *old_pwd = NULL;
  char *cur_pwd = NULL;
  
  current_dir = getcwd(NULL, 0);

    if (current_dir == NULL)
    {
        perror("getcwd() error");
        return;
    }

    old_pwd = current_dir;

    if (input[1] == NULL)
    {
        if (chdir(bring_path("HOME")) != 0)
        {
            perror("chdir() error");
        }
    }
    else
    {
        if (chdir(input[1]) != 0)
        {
            perror("chdir() error");
        }
    }

    cur_pwd = getcwd(NULL, 0);

    if (cur_pwd == NULL)
    {
        perror("getcwd() error");
        return;
    }

    printf("Current directory: %s\n", cur_pwd);

    //free(current_dir);
    //free(cur_pwd);
}
