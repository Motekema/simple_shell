#include "Our_Shell.h"
#include <unistd.h>
#include <stdlib.h>

#define MAX_INPUT_LENGTH 100

/**
 * main - Entry point for the simple shell program.
 *
 * This program implements a basic shell that reads and executes user commands.
 * It continuously prompts the user for input, reads the input, and processes
 * it. If the input is "exit", the shell displays a termination message and
 * exits the loop. If the input is "env", the program prints the current
 * environment variables to the standard output.
 *
 * Return: Always 0.
 */

int main(void)
{
char input[MAX_INPUT_LENGTH];

while (1)
{
write(1, "#Motekema&Joshua$ ", 18);
read(0, input, sizeof(input));

/* Remove the newline character from input */
input[strcspn(input, "\n")] = '\0';

/* Check if the input is the exit command */
if (strcmp(input, "exit") == 0)
{
write(1, "Exiting the shell...\n", 21);
break;
}
else if (strcmp(input, "env") == 0)
{
/* Print the current environment variables */
extern char **environ;
char **env = environ;
while (*env != NULL)
{
write(1, *env, strlen(*env));
write(1, "\n", 1);
env++;
}
}
else
{
/* If no special command is recognized, print a message */
char unknown[] = "Unknown command: ";
write(1, unknown, sizeof(unknown) - 1);
write(1, input, strlen(input));
write(1, "\n", 1);
}
}
return (0);
}
