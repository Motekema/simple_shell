#ifndef Our_Shell_H
#define Our_Shell_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <errno.h>
#include <signal.h>

extern char **environ;
extern int errno;

/**
 * struct select_function - a struct array of functions
 * @command: a pointer to the caharacter of the command string
 * @funcptr: a pointer to a function
 */

typedef struct select_function
{
char *command;
int (*funcptr)(char **line);
} selecte;

void sigintHandler(int sig_num __attribute__((unused)));
void printprompt(int i);
int exitor(char *line[]);
int cater(char *line[]);
int getstr(char *str);
int shellprocessor(char **line, char **argv);
char **strbrk(char *line, char c);
int _getline(char **line, size_t *len);
void farewell(void);
void description(void);
void printstar(void);
void printstr(char *s);
int strleng(char *s);
void strcopy(char *src, char *dest);
int strcomp(char *str, char *equ);
void strmix(char *src, char *dest);
int lister(char **line);
int (*getfunc(char *str))(char **line);
int echorr(char *line[]);
int builtincom(char **line);
int changedire(char **line);
int pwder(char *line[]);
int envir(char *line[]);
int maker(char *line[]);
char _getchar(void);
char *stringer(char *line, int i, char *str, char c);

#endif
