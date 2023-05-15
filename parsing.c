#include "shell.h"

char **parse(char *str)
{
    int size = 2;
    char **args;
    int a_i = 0;
    char *to_ken;

    args = malloc(size * sizeof(char *));
    if (args == NULL)
      return (NULL);
    to_ken = strtok(str, " \t\n");
    while (to_ken != NULL)
    {
        args[a_i] = _strdup(to_ken);
        a_i++;
        if (a_i == size) 
        {
            size *= 2;
            args = realloc(args, size * sizeof(char *));
        }
        if (args == NULL)
        {
            free_buff(args);
            return NULL;
        }
        to_ken = strtok(NULL, " \t\n");
    }
    args[a_i] = NULL;
    return (args);
}