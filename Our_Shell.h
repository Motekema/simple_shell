#ifndef _OUR_SHELL_H_
#define _OUR_SHELL_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h> 

char **tokenize_input(const char *input);
void execute_command(const char *command, char *const arguments[]);

#endif
