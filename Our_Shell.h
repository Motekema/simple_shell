#ifndef _OUR_SHELL_H_
#define _OUR_SHELL_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdbool.h>

#define MAX_INPUT_LENGTH 100

void parse_input(char *input, char **args, int *argc);
void execute_command(char **args);
bool commandExists(const char *command);

#endif
