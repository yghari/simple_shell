#include "shell.h"

char *check_path(char **paths, char *input)
{
    char *path_cmd = NULL;

    if (access(input, F_OK | X_OK) == 0)
        return _strdup(input);
    for (int i = 0; paths[i] != NULL; i++)
    {
        path_cmd = _strcat(paths[i], input);   
        if (access(path_cmd, F_OK | X_OK) == 0) 
        {
          return path_cmd;
          
        }
        free(path_cmd);
    }
    free_buff(paths);
    return (NULL);
}
