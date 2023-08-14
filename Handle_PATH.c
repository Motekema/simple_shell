#include "Our_Shell.h"

#define MAX_INPUT_LENGTH 100

char *path_copy = strdup(path);
bool commandExists(const char *command) {

	char *path = getenv("PATH");
	if (path == NULL) {
		perror("Error finding PATH");
		exit(1);
	}
	char *dir = strtok(path_copy, ":");
	while (dir != NULL) {
		char cmd_path[MAX_INPUT_LENGTH];
		int cmd_path_gen = strlen(dir) +1 + strlen(command) +1;
		if (cmd_path_gen > MAX_INPUT_LENGTH) {
			char error_message[] = "Command path is too long\n";
			write(STDERR_FILENO, error_message, sizeof(error_message) - 1);
			exit(1);
		}
		strcpy(cmd_path, dir);
		strcat(cmd_path, "/");
		strcat(cmd_path, command);
		if (access(cmd_path, X_OK) == 0) {
			free(path_copy);
			return true;
		}
		dir = strtok(NULL, ":");
	}

	int main(void) {

		char input[MAX_INPUT_LENGTH];
		char *args[MAX_INPUT_LENGTH];
		char *ticket;
		int status;

		while (1) {
			char prompt[] = "#Motekema&Joshua$ ";
			write(STDOUT_FILENO, prompt, sizeof(prompt) - 1);
			if (fgets(input, sizeof(input), stdin) == NULL) {
				break;
			}
			input[strcspn(input, "\n")] = '\0';
			ticket = strtok(input, " ");
			int argc = 0;
			while (ticket != NULL) {
				args[argc++] = ticket;
				ticket = strtok(NULL, " ");
			}
			args[argc] = NULL;
			if (argc > 0) {
				if (commandExists(args[0])) {
					pid_t pid = fork();
					if (pid == 0) {
						execvp(args[0], args);
						char error_message[] = "Error with execvp\n";
						write(STDERR_FILENO, error_message, sizeof(error_message) - 1);
						exit(1);
					} else if (pid < 0) {
						char error_message[] = "Error with forking\n";
						write(STDERR_FILENO, error_message, sizeof(error_message) - 1);
					} else {
						waitpid(pid, &status, 0);
					}
				} else {
					char cmd_not_found[] = "Command not found\n";
					write(STDERR_FILENO, cmd_not_found, sizeof(cmd_not_found) - 1);
				}
			}
		}
	}
	return (0);
}
