#include "Our_Shell.h"


/**
 * parse_input - Parse the input string into arguments.
 *
 * This function takes an input string and tokenizes it using space (' ')
 * as a delimiter. The parsed arguments are stored in the 'args' array,
 * and the number of arguments is updated in the 'argc' variable.
 *
 * @param input The input string to be parsed.
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
 * execute_command - Execute a command with the provided arguments.
 *
 * This function attempts to execute a command using the 'execvp' system call.
 * The 'args' array should contain the command to be executed first element,
 * followed by its arguments. If the execution fails, an error is displayed
 * with a more informative message, the program exits with a failure status.
 *
 * @param args An array of arguments, first argument is the command to execute.
 */

void execute_command(char **args)
{
if (execvp(args[0], args) == -1)
{
perror("Error of executing command");
exit(EXIT_FAILURE);
}
}
