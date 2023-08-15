#include "Our_Shell.h"

#define MAX_INPUT_LENGTH 100

/**
 * main - Entry point for the simple shell program.
 *
 * Implements a basic shell that reads and executes user commands.
 *
 * Return: Always 0.
 */

int main(void)
{
char input[MAX_INPUT_LENGTH];
char *args[2]; /* Only one argument allowed */
pid_t pid;
int status;

while (1)
{
write(STDOUT_FILENO, "#Motekema&Joshua$ ", 14); /* Display the prompt */

if (fgets(input, sizeof(input), stdin) == NULL)
{
/* Handle end of file (Ctrl+D) */
write(STDOUT_FILENO, "\n", 1);
break;
}

input[strcspn(input, "\n")] = '\0';

args[0] = input;
args[1] = NULL;

pid = fork();
if (pid == 0)
{
/* Child process */
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
/* Parent process */
waitpid(pid, &status, 0);
}
}
return (0);
}
