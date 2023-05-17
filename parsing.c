#include "shell.h"

char **parse(char *str)
{
    char **args = NULL;
    int a_i = 0;
    char *to_ken = NULL;
    int len = 0;

    len = length_of_paths(str,DELIMITER2);
    args = malloc(sizeof(char *) * (len + 1));
    if (!args)
    {
        return (NULL);
    }
    args[len] = 0;
    to_ken = strtok(str, DELIMITER2);
    while (to_ken)
    {
        args[a_i] = _strdup(to_ken);
        if (!args[a_i]) 
        {
            free_buff(args);
            return NULL;
        }
        a_i++;
        to_ken = strtok(NULL, DELIMITER2);
    }
    return (args);
}
