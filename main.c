#include "Our_Shell.h"
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

#define DELIMITER " \t\r\n\a"

int main(void)
{
char *path = getenv("PATH");
if (!path)
{
perror("PATH environment variable not found");
exit(EXIT_FAILURE);
}

while (1)
{
char *input = get_input();
input[strcspn(input, "\n")] = '\0';  /* Remove the newline character */

char *token = strtok(input, DELIMITER);
if (!token)
{
free(input);
continue;
}

char *full_path = search_path(token, path);
if (!full_path)
{
printf("%s: command not found\n", token);
free(input);
continue;
}

pid_t pid = fork();  /* Fork a new process */
if (pid == 0)
{  /* Child process */
execv(full_path, (char *[])
{full_path, NULL});
perror("Error");  /* This line will be reached only if execv fails */
free(full_path);
free(input);
exit(EXIT_FAILURE);
}
else if (pid > 0)
{  /* Parent process */
waitpid(pid, NULL, 0);  /* Wait for the child process to finish */
}
else
{
perror("Fork failed");
}

free(full_path);
free(input);
}

return (0);
}

