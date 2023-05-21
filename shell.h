#ifndef SHELL_H
#define SHELL_H

#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <time.h>
#include <stdbool.h>
#include <signal.h>

#define DELIMITER1 ":"
#define DELIMITER2 " \t\n"

extern  char **environ;
extern __sighandler_t signal(int __sig, __sighandler_t __handler);

typedef struct token 
{
  const char *cmnd;
}s_token;

typedef struct t_builti
{
  char *exit;
  char *c_d;
  char *en_v;
} t_builti;

typedef struct t_flags
{
	bool intrctv;
  unsigned int count;
} t_flags;

void handle_signal(int m);
void env_cmd(void);
int        length_of_paths(char *path, char *del);
int _strlen(char *s);
int _strncmp(const char *s1, const char *s2, size_t n);
char *_strdup(char *str);
char *_strcat(char *dest, char *src);
void free_buff(char **buf);
char **parse(char *str, char *del);
int    prompt(bool flag);
char *bring_path(char *path);
// char **pathing(char *str);
char *check_path(char **paths, char *input);
int execution(char **input, char *test);
int magic(char *input, ssize_t size, char **d_str);
void  cd_cmd(char **input);
int handle_builtins(char **d_str);

#endif
