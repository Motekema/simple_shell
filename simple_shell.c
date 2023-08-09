#include "Our_Shell.h"
#include <stdio.h>
#include <unistd.h>

/**
 * main - Entry point of the my shell program
 *
 * Description:
 * This program implements a basic shell that reads and executes commands
 * entered by the user. It displays a prompt, reads user input, parses it
 * into arguments, and then attempts to execute the specified command.
 *
 * Return: Always 0
 */

int main(void)
{

char input[1000];
char *args[1000];
char *ticket;

while {
write(STDOUT_FILENO, "Motekema&Joshua$", 16);
if (fgets(input, sizeof(input), stdin) == NULL)
{
break;
}

input[strcspn(input, "\n")] = '\0';

int argc = 0;
ticket = strtok(input, " ");

while (ticket != NULL)
{
args[argc++] = ticket;

ticket = strtok(NULL, " ");
}

args[argc] = NULL;
if (execvp(args[0], args) == -1)
{
perror("Error of execvp");
}
}
return (0);
}
