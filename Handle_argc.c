#include "Our_Shell.h"

/**
 * parse_input - Parses the input string into arguments.
 *
 * @param input The input string to parse.
 * @param args An array to store the parsed arguments.
 * @param argc A pointer to an integer to store the number of arguments.
 */

void parse_input(char *input, char **args, int *argc)
{
char *ticket = strtok(input, " ");
*argc = 0;
while (ticket != NULL)
{
args[(*argc)++] = ticket;
ticket = strtok(NULL, " ");
}
args[*argc] = NULL;
}

/**
 * execute_command - Executes a command with the provided arguments.
 *
 * @param args An array of arguments, where the first argument is the command to execute.
 */

void execute_coommand(char **args)
{
if (execvp(args[0], args) == -1)
{
perror("Error of executing command");
exit(EXIT_FAILURE);
}
}
