#include "Our_Shell.h"

#define MAX_INPUT_LENGTH 1024

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

while (1)
{
write(1, "#Motekema&Josua$ ", 13);
read(0, input, sizeof(input));

/* Remove the newline character from input */
input[strcspn(input, "\n")] = '\0';

/* Check if the input is the exit commant */
if (strcmp(input, "exit") == 0)
{
write(1, "Exiting the shell...\n", 21);
break;
}
char unknown[] = "Unknown command: ";
write(1, unknown, sizeof(unknown));
write(1, input, strlen(input));
write(1, "\n", 1);
}
return (0);
}
