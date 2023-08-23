#ifndef _OUR_SHELL_H_
#define _OUR_SHELL_H_


#define MAX_INPUT_LENGTH 100

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>
#include <dirent.h>
#include <stdbool.h>

bool commandExists(const char *command);
void parse_input(char *input, char **args, int *argc);
void execute_command(char **args);
bool commandExists(const char *command);

#endif
