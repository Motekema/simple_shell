#ifndef OUR_SHELL_H_
#define OUR_SHELL_H_

#include <limits.h>
#include <fcntl.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

/* Read/Write buffers */
#define WRITE_BUF_SIZE 1024
#define BUF_FLUSH -1
#define READ_BUF_SIZE 1024

/* 1 using system getline() */
#define USE_STRTOK 0
#define USE_GETLINE 0

/* Command chaining */
#define CMD_AND 2
#define CMD_CHAIN 3
#define CMD_NORM 0
#define CMD_OR 1

/* Convert_number() */
#define CONVERT_LOWERCASE 1
#define CONVERT_UNSIGNED 2

#define HIST_FILE ".simple_shell_history"
#define HIST_MAX 4096

/* Using system getline() */
#define USE_GETLINE 0
#define USE_STRTOK 0

extern char **environ;

/**
* struct liststr - singly linked list
* @num: the number fields
* @str: a strings
* @next: point the next node
*/
typedef struct liststr
{
char *str;
int num;
struct liststr *next;
} list_t;

/**
* struct passinfo - contains pseudo-arguements to pass into a function,
* allowing uniform prototype for function pointer struc
* @readfd: the fd from which to read line input
* @histcount: the history line number count
* @env_changed: on if environ was changed
* @status: the return status of the last exec'd command
* @cmd_buf: address of pointer to cmd_buf, on if chaining
* @fname: the program filename
* @env: linked list local copy of environ
* @cmd_buf_type: type of cmd_buf (CMD_AND, CMD_CHAIN)
* @environ: custom modified copy of environ from LL env
* @history: the history node
* @argc: the argument count
* @arg: a string generated from getline containing arguements
* @line_count: the error count
* @err_num: the error code for exit()s
* @linecount_flag: if on count this line of input
* @alias: the alias node
* struct passinfo - contains pseudo-arguements to pass into a function
* @argv:an array of strings generated from arg
* @path: a string path for the current command
*/
typedef struct passinfo
{
char **environ;
int env_changed;
int status;

list_t *env;
list_t *history;
list_t *alias;

int err_num;
int linecount_flag;
char *fname;
char *arg;
char **argv;
char *path;
int argc;
unsigned int line_count;

char **cmd_buf; /* point to cmd_buf_type ; chain buffer,memory mangement */
int cmd_buf_type;
int readfd;
int histcount;
} info_t;

#define INFO_INIT \
{NULL, NULL, NULL, 0, 0, 0, 0, NULL, NULL, NULL, NULL, NULL, 0, 0, NULL, \
0, 0, 0}

/**
* struct builtin - contains a builtin string and related function
* @type: the builtin command flag
* @func: the function
*/

typedef struct builtin

{

char *type;
int (*func)(info_t *);

} builtin_table;

/* Storage.c */
int dfree(void **);

/* built_ins.c */
int _Our_exit(info_t *);
int _Our_cd(info_t *);
int _Our_help(info_t *);

/* built-ins_1.c */
int _Our_history(info_t *);
int _Our_alias(info_t *);

/* simple_shell.c */
int hsh(info_t *, char **);
void fork_cmd(info_t *);
int find_builtin(info_t *);
void find_cmd(info_t *);

/* strings.c */
int _strgen(char *);
int _strcmp(char *, char *);
char *starts_with(const char *, const char *);
char *_strcat(char *, char *);

#endif
