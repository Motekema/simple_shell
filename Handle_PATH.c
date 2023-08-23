#include "Our_Shell.h"
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

/**
 * Fuction search path
 *
 * This function searches for an executable command within the specified path.
 *
 * @param command The name of the command to search for.
 * @param path The search path to look for the command.
 * @return The full path to the executable command if found, otherwise NULL.
 */

char *search_path(char *command, char *path)
{
char *token = strtok(path, ":");
while (token)
{
char *full_path = malloc(MAX_PATH_SIZE);
if (!full_path)
{
perror("Memory allocation fails");
exit(EXIT_FAILURE);
}
snprintf(full_path, MAX_PATH_SIZE, "%s/%s", token, command);
if (access(full_path, X_OK) == 0)
{
return (full_path);
}
free(full_path);
token = strtok(NULL, ":");
}
return (NULL);
}

