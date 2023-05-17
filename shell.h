#ifndef SHELL_H
#define SHELL_H

#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <errno.h>

extern  char **environ;

typedef struct token 
{
  const char *cmnd;
}s_token;

int _strlen(char *s);
int _strncmp(const char *s1, const char *s2, size_t n);
char *_strdup(char *str);
char *_strcat(char *dest, char *src);
void free_buff(char **buf);
char **parse(char *str);
int    prompt(void);
char *bring_path(char *path);
char **pathing(char *str);
char *check_path(char **paths, char *input);
int execution(char **input, char *test);
int magic(char *input, ssize_t size);
void  cd_cmd(char **input);

#endif
