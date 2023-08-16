#include "Our_Shell.h"

#define MAX_INPUT_LENGTH 100

int main(void)
{
char input[MAX_INPUT_LENGTH];

while (1)
{
write(1, "SimpleShell> ", 13);
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
for (char **env = environ; *env != NULL; env++)
{
write(1, *env, strlen(*env));
write(1, "\n", 1);
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
