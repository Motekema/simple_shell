#include "Our_Shell.h"

#define MAX_INPUT_LENGTH 100

/**
* main - Entry point for the simple shell program.
*
* Implements a basic shell that reads and executes user commands.
*
* Return: Always 0.
*/

void execute_command(char *command) {
pid_t pid = fork();

if (pid == 0)
{  
/* Child process */
char *args[] = {command, NULL};
execve(command, args, NULL);
perror("simple_shell");
exit(EXIT_FAILURE);
}
else if (pid > 0)
{ 
/* Parent process */
int status;
waitpid(pid, &status, 0);
}
else
{
perror("simple_shell");
}
}

int main()
{
char input[MAX_INPUT_SIZE];

while (1)
{
printf("#Motekema&Joshua$ ");

if (fgets(input, sizeof(input), stdin) == NULL)
{
printf("\nExiting simple_shell\n");
break;
}

/* Remove trailing newline */
input[strcspn(input, "\n")] = '\0';

execute_command(input);
}

return (0);
}
