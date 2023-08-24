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
* @err_num: error code for exit()s
* @linecount_flag:  on count if this line of input
* @alias: alias node
* struct passinfo - contains pseudo-arguements pass into a function
* @argv: array of strings generated from arg
* @path: an string path for the current command
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

char **cmd_buf; /* point to cmd_buf_type ; chain buffer, storage mangement */
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

/* environ.c */
int _Our_setenv(info_t *);
int _Our_env(info_t *);
int _Our_unsetenv(info_t *);
char *_getenv(info_t *, const char *);
int populate_env_list(info_t *);


/* variables.c */
int is_chain(info_t *, char *, size_t *);
int replace_string(char **, char *);
void check_chain(info_t *, char *, size_t *, size_t, size_t);
int replace_vars(info_t *);
int replace_alias(info_t *);

/* Our_lists.c */
void free_list(list_t **);
list_t *add_node(list_t **, const char *, int);
list_t *add_node_end(list_t **, const char *, int);
int delete_node_at_index(list_t **, unsigned int);
size_t print_list_str(const list_t *);

/* Our_lists1.c */
char **list_to_strings(list_t *);
size_t list_len(const list_t *);
size_t print_list(const list_t *);
ssize_t get_node_index(list_t *, list_t *);
list_t *node_starts_with(list_t *, char *, char);

/* Our_history.c */
int read_history(info_t *info);
int write_history(info_t *info);
int build_history_list(info_t *info, char *buf, int linecount);
char *get_history_file(info_t *info);
int renumber_history(info_t *info);

/* Our_getenv.c */
int _unsetenv(info_t *, char *);
char **get_environ(info_t *);
int _setenv(info_t *, char *, char *);

/* Our_environ.c */
int _myenv(info_t *);
int populate_env_list(info_t *);
int _mysetenv(info_t *);
char *_getenv(info_t *, const char *);
int _myunsetenv(info_t *);

/* Our_getinfo.c */
void set_info(info_t *, char **);
void clear_info(info_t *);
void free_info(info_t *, int);

/* Our_getline.c */
int _getline(info_t *, char **, size_t *);
ssize_t get_input(info_t *);
void sigintHandler(int);

/* Our_errors1.c */
char *convert_number(long int, int, int);
int _erratoi(char *);
void print_error(info_t *, char *);
void remove_comments(char *);
int print_d(int, int);

/* Our_atoi.c */
int is_delim(char, char *);
int _isalpha(int);
int interactive(info_t *);
int _atoi(char *);

/* Our_realloc.c */
void ffree(char **);
char *_memset(char *, char, unsigned int);
void *_realloc(void *, unsigned int, unsigned int);

/* toem_tokenizer.c */
char **strtow2(char *, char);
char **strtow(char *, char *);

/* Our_exits.c */
char *_strncpy(char *, char *, int);
char *_strchr(char *, char);
char *_strncat(char *, char *, int);

/* _loophsh.c */
int loophsh(char **);

/* toem_errors.c */
int _eputchar(char);
void _eputs(char *);
int _putsfd(char *str, int fd);
int _putfd(char c, int fd);

/* Our_shloop.c */
void find_cmd(info_t *);
int hsh(info_t *, char **);
int find_builtin(info_t *);
void fork_cmd(info_t *);

/* Our_parser.c */
char *dup_chars(char *, int, int);
int is_cmd(info_t *, char *);
char *find_path(info_t *, char *, char *)

#endif
