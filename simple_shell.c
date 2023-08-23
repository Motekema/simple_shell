#include "Our_Shell.h"

/**
 * copyarray - a function to copy string array to another string array variable
 * @line: a string array to be copied
 * 
 * Return: returns the copied array
 */

char **copyarray(char **line)
{
char **array;
int i = 1;

array = malloc(64);
if (!array)
return (NULL);

while (line[i] != NULL)
{
array[(i - 1)] = malloc(32);
if (!array[(i - 1)])
return (NULL);

strcopy(line[i], array[(i - 1)]);
i++;
}

return (array);
}

/**
 * sigintHandler - a function to handle the ctrl-c signal
 * @sig_num: an integer signal indicator
 *
 * Return: void function
 */

void sigintHandler(int sig_num __attribute__((unused)))
{
signal(SIGINT, sigintHandler);
write(1, "\n", 2);
printprompt(0);
fflush(stdout);
}

/**
 * main - a the main function of the shell
 * @argc: the number of arguments given
 * @argv: an array of given argument strings
 *
 * Return: returns an integer
 */

int main(int argc __attribute__((unused)), char **argv)
{
char *line;

line = malloc(256);
if (!line)
{
perror("Allocation");
exit(1);
}

if (!isatty(STDIN_FILENO))
{
if (getstr(line) == (-1))
{
write(1, "\n", 2);
exit(1);
}
if (shellprocessor(strbrk(line, ' '), argv) == -1)
{
perror("Error");
}

exit(0);
}

do {
printprompt(0);
if (getstr(line) == (-1))
{
write(1, "\n", 2);
exit(0);
}

if ((shellprocessor(strbrk(line, ' '), argv)) == -1)
{
perror("Error");
}
} while (1);

return (0);
}
