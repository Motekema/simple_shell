#include "Our_Shell.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

#define MAX_INPUT_SIZE 1024

/**
* main - Entry point for the simple shell program.
*
* Implements a basic shell that reads and executes user commands.
*
* Return: Always 0.
*/

int main(void)
{
char input[MAX_INPUT_SIZE];

while (1)
{
printf("#Motekema&Joshua$ ");
if (fgets(input, sizeof(input), stdin) == NULL)
{
if (feof(stdin))
{
printf("\nExiting the shell...\n");
break;
}
}

input[strcspn(input, "\n")] = '\0';  /* Remove the newline character */

pid_t pid = fork();  /* Fork a new process */
if (pid == 0)
{  /* Child process */
if (execlp(input, input, (char *)NULL) == -1)
{
perror("Error");
exit(EXIT_FAILURE);
}
}
else if (pid > 0)
{  /* Parent process */
waitpid(pid, NULL, 0);  /* Wait for the child process to finish */
}
else
{
perror("Fork failed");
}
}

return (0);
}
