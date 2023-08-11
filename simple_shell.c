/*
 * Simple Shell Implementation
 * A basic shell program that reads user commands, forks child processes to execute them,
 * and provides a simple command-line interface.
 */

#include "Our_Shell.h"
#define MAX_INPUT_LENGTH 100


/**
 * @brief Main function of the Simple Shell program.
 *
 * This function implements a basic shell that reads user commands, tokenizes them,
 * and forks a child process to execute the command. It provides a simple command-line interface.
 *
 * @return 0 on successful execution.
 */


int main(void)
{
char input[MAX_INPUT_LENGTH];
char *args[MAX_INPUT_LENGTH];
char *token;
pid_t pid;
int status;
int argc = 0;
while (1)
{
write(STDOUT_FILENO, prompt, sizeof(prompt) - 1);
if (fgets(input, sizeof(input), stdin) == NULL)
{
break;
}
input[strcspn(input, "\n")] = '\0';
token = strtok(input, " ");
while (token != NULL)
{
args[argc++] = token;
token = strtok(NULL, " ");
}
args[argc] = NULL;
((pid = fork()) == 0)
{
execvp(args[0], args);
perror("Error of execvp");
exit(1);
}
else if (pid < 0)
{
perror("Error of forking");
}
else
{
waitpid(pid, &status, 0);
}
}
return (0);
}
