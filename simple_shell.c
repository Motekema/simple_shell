#include "Our_Shell.h"
#define MAX_INPUT_LENGTH 100

/**
 * Tokenizes the user input command.
 *
 * This function takes the user input string.
 * Tokenizes it based on space characters.
 * It populates the args array with pointers to the tokens.
 * Returns the number of tokens found.
 *
 * @param input The user input command.
 * @param args An array of pointers to store the tokens.
 * @return The number of tokens.
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
