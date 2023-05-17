#include "shell.h"

char *bring_path(char *path)
{
    int path_len = _strlen(path);

    for (char **env = environ; *env != NULL; env++)
    {
        if (_strncmp(*env, path, path_len) == 0 && *(*env + path_len) == '=') 
        {
            return (*env + path_len + 1);
        }
    }
    printf("path not found\n");
    return (NULL);
}

char **pathing(char *str)
{
    char **paths = NULL;
    int i = 0;
    char *path = NULL;
    char *c_path = NULL;

    paths = malloc(sizeof(char *) * (length_of_paths(str, DELIMITER1) + 1));
    if (!paths)
    {
        return (NULL);
    }
    path = strtok(str, DELIMITER1);
    while (path)
    {
        paths[i] = _strdup(path);
        if (!paths[i])
        {
            free_buff(paths);
            return (NULL);
        }
        i++;
        path = strtok(NULL, DELIMITER1);
    }
    paths[i] = 0;
    return (paths);
}
