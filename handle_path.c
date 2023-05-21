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

int        length_of_paths(char *path, char *del)
{
    int        length;
    char        *line, *copied_path;
    length = 0;
    copied_path = strdup(path);
    line = strtok(copied_path, del);
    while (line)
    {
        length++;
        line = strtok(NULL, del);
    }
    free(copied_path);
    return (length);
}