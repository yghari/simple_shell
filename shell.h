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
/**
 * struct token - Structure for a token
 * @cmnd: The command string
 *
 * Description: This structure represents a token containing a command string.
 */
typedef struct token
{
	const char *cmnd;
} s_token;
/**
 * struct t_builti - Structure for built-in commands
 * @exit: The "exit" command
 * @c_d: The "cd" command
 * @en_v: The "env" command
 *
 * Description: This structure represents built-in commands in the shell.
 * Each command is stored as a string in the respective member.
 */
typedef struct t_builti
{
	char *exit;
	char *c_d;
	char *en_v;
} t_builti;
/**
 * struct t_flags - Structure for shell flags
 * @intrctv: Flag indicating if the shell is interactive
 * @count: Number of commands executed in the shell
 *
 * Description: This structure holds flags and counts for the shell.
 * The 'intrctv' flag indicates whether the shell is interactive or not.
 * The 'count' member keeps track of the number of commands executed.
 */
typedef struct t_flags
{
	bool intrctv;
	unsigned int count;
} t_flags;

void handle_signal(int m);
int env_cmd(void);
int length_of_paths(char *path, char *del);
int _strlen(char *s);
int _strncmp(const char *s1, const char *s2, size_t n);
char *_strdup(char *str);
char *_strcat(char *dest, char *src);
void free_buff(char **buf);
char **parse(char *str, char *del);
void prompt(bool flag);
char *bring_path(char *path);
char *check_path(char **paths, char *input);
int execution(char **input, char *test);
int magic(char *input, ssize_t size, char **d_str);
void  cd_cmd(char **input);
int handle_builtins(char **d_str, char *str);
int free_path(char *path, char *input, char **str);
int _putstring(char *s);
int _putchar(char c);
int free_cmd(char **d_str, char *g_path, char *path_cmd);
int _fput_helper(int fd, int number);
int _fputnumber(int fd, int number);
int _fputs(int fd, char *s);
int _fprint(int fd, const char *format, ...);
int exit_status(int update, int n_status);
#endif
