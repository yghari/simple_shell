#ifndef SHELL_H
#define SHELL_H

#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>


extern  char **environ;

typedef struct token 
{
  const char *cmnd;
}s_token;

void    prompt(void);
char    **parse(char *token);

#endif
