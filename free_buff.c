#include "shell.h"

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
