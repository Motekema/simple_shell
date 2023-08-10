#include "Our_Shell.h"

#define MAX_INPUT_LENGTH 100

int main(void) {
char input[MAX_INPUT_LENGTH];
char *args[MAX_INPUT_LENGTH];
char *token;
pid_t pid;
int status;

while (1) {
char prompt[] = "#Motekema&Joshua$ ";
write(STDOUT_FILENO, prompt, sizeof(prompt) - 1);

if (fgets(input, sizeof(input), stdin) == NULL) {
break;
}

input[strcspn(input, "\n")] = '\0';

int argc = 0;
token = strtok(input, " ");
while (token != NULL) {
args[argc++] = token;
token = strtok(NULL, " ");
}
args[argc] = NULL;

if ((pid = fork()) == 0) {
execvp(args[0], args);
perror("Error of execvp");
exit(1);
} else if (pid < 0) {
perror("Error of forking");
} else {
waitpid(pid, &status, 0);
}
}
return (0);
}

