#include "shell.h"

char *bring_path(char *path)
{
    int path_len = _strlen(path);

    for (char **env = environ; *env != NULL; env++)
    {
        if (_strncmp(*env, path, path_len) == 0 && *(*env + path_len) == '=') {
            return (*env + path_len + 1);
        }
    }
    printf("path not found\n");
  
    return (NULL);
}

char **pathing(char *str)
{
    int size = 2;
    char **paths = NULL;
  
    paths = malloc(size * sizeof(char *));
    if (paths == NULL)
        return (NULL);
  
    int i = 0;
    char *path;
    char *c_path;
  
    c_path = _strdup(str);
    path = strtok(c_path, ":");
    while (path != NULL)
    {
        if (i == size - 1)
        {
            size *= 2;
            paths = realloc(paths, size * sizeof(char *));    
            if (paths == NULL)
            {
              free_buff(paths);
              return NULL;
            }
        }
        paths[i] = _strdup(path);
        if (paths[i] == NULL)
            return (NULL);
        i++;
        path = strtok(NULL, ":");
    }
    paths[i] = NULL;
    free(c_path);
    return (paths);
}