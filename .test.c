// #include <stdio.h>
// #include <signal.h>
// #include <unistd.h>
// #include <string.h>
// #include <stdlib.h>

// #define DELIMITER ":"

// int        length_of_paths(char *path)
// {
//     int        length;
//     char        *line, *copied_path;
//     length = 0;
//     copied_path = strdup(path);
//     line = strtok(copied_path, DELIMITER);
//     while (line)
//     {
//         length++;
//         line = strtok(NULL, DELIMITER);
//     }
//     free(copied_path);
//     return (length);
// }

// void        free_previous_allocation(char **pointer, int current_position)
// {
//     int    index;

//     index = 0;
//     while (index < current_position)
//     {
//         free(pointer[index]);
//         index++;
//     }
//     free(pointer);
// }

// char        **get_splited_path(char *path)
// {
//     int    len, current;
//     char    **backets;
//     char    *line;

//     len = length_of_paths(path);
//     backets = malloc(sizeof(char *) * (len + 1));
//     if (!backets)
//         return (NULL);
//     backets[len] = 0;
//     current = 0;
//     line = strtok(path, DELIMITER);
//     while (line)
//     {
//         backets[current] = strdup(line);
//         if (!backets[current])
//         {
//             free_previous_allocation(backets, current);
//             return (NULL);
//         }
//         current++;
//         line = strtok(NULL, DELIMITER);
//     }
//     return (backets);
// }

// void        free_splitter(char ***spliter)
// {
//     char    **pointer;

//     pointer = *spliter;
//     while (*pointer)
//     {
//         free(*pointer);
//         pointer++;
//     }
//     free(*spliter);
//     *spliter = NULL;
// }

// int        main(int ac, char *av[], char **env)
// {
//     int current= 0;
//     char        **pointer, **path2d;
//     char        *path, *line;
//     pointer = env;
//     while (*pointer)
//     {
//         char *first = strtok(*pointer, "=");
//         if (!strcmp(first, "PATH"))
//         {
//                path = strtok(NULL, "=");
//                break;
//         }
//         pointer++;
//     }
//     path2d = get_splited_path(path);
//     pointer = path2d;
//     while (*pointer)
//     {
//         printf("%s\n", *pointer);
//         pointer++;
//     }
//     // free
//     free_splitter(&path2d);
//     return (0);
// }
