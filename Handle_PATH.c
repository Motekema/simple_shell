#include "Our_Shell.h"

#define MAX_INPUT_LENGTH 100

bool commandExists(const char *command);
void executeCommand(char *args[]);

bool commandExists(const char *command)
{
    char *path = getenv("PATH");
    char *path_copy;
    char cmd_path[MAX_INPUT_LENGTH];
    char *dir;
    int cmd_path_gen;
    
    if (path == NULL)
    {
        perror("Error finding PATH");
        exit(1);
    }

    path_copy = strdup(path);
    dir = strtok(path_copy, ":");
    
    while (dir != NULL)
    {
        cmd_path_gen = strlen(dir) + 1 + strlen(command) + 1;
        
        if (cmd_path_gen > MAX_INPUT_LENGTH)
        {
            char error_message[] = "Command path is too long\n";
            write(STDERR_FILENO, error_message, sizeof(error_message) - 1);
            exit(1);
        }

        strcpy(cmd_path, dir);
        strcat(cmd_path, "/");
        strcat(cmd_path, command);
        
        if (access(cmd_path, X_OK) == 0)
        {
            free(path_copy);
            return (true);
        }
        dir = strtok(NULL, ":");
    }
    free(path_copy);
    return (false);
}

void executeCommand(char *args[])
{
    pid_t pid = fork();
    if (pid == 0)
    {
        execvp(args[0], args);
        perror("Error executing command");
        exit(1);
    }
    else if (pid < 0)
    {
        perror("Error with forking");
    }
    else
    {
        int status;
        waitpid(pid, &status, 0);
    }
}

int main(void)
{
    char input[MAX_INPUT_LENGTH];
    char *args[MAX_INPUT_LENGTH];
    char *ticket;
    int argc = 0;

    while (1)
    {
        char prompt[] = "#Motekema&Joshua$ ";
        write(STDOUT_FILENO, prompt, sizeof(prompt) - 1);

        if (fgets(input, sizeof(input), stdin) == NULL)
        {
            break;
        }

        input[strcspn(input, "\n")] = '\0';
        ticket = strtok(input, " ");
        argc = 0;

        while (ticket != NULL)
        {
            args[argc++] = ticket;
            ticket = strtok(NULL, " ");
        }

        args[argc] = NULL;

        if (argc > 0)
        {
            if (commandExists(args[0]))
            {
                executeCommand(args);
            }
            else
            {
                char cmd_not_found[] = "Command not found\n";
                write(STDERR_FILENO, cmd_not_found, sizeof(cmd_not_found) - 1);
            }
        }
    }
    return (0);
}
