#include "Our_Shell.h"

/**
*_eputs - it prints an input string
* @str: it is the string to be printed
*
* Return: Nothing
*/
void _eputs(char *str)
{
int y = 0;

if (!str)
return;
while (str[y] != '\0')
{
_eputchar(str[y]);
y++;
}
}

/**
* _eputchar - it writes the character c to stderr
* @c: The characters to print
*
* Return: On success 1.
* On error, -1 is returned and errors are set appropriately.
*/
int _eputchar(char c)
{
static int y;
static char buf[WRITE_BUF_SIZE];

if (c == BUF_FLUSH || y >= WRITE_BUF_SIZE)
{
write(2, buf, y);
y = 0;
}
if (c != BUF_FLUSH)
buf[y++] = c;
return (1);
}

/**
* _putfd - it writes character c to given fd
* @c: The characters to print
* @fd: The filedescriptor that will write to
*
* Return: On success 1.
* On error, -1 is returned, and errors are set appropriately.
*/
int _putfd(char c, int fd)
{
static int y;
static char buf[WRITE_BUF_SIZE];

if (c == BUF_FLUSH || y >= WRITE_BUF_SIZE)
{
write(fd, buf, y);
y = 0;
}
if (c != BUF_FLUSH)
buf[y++] = c;
return (1);
}

/**
*_putsfd - it print a input string
* @str: string to be printed
* @fd: filedescriptor to write to
*
* Return: number of chars put
*/
int _putsfd(char *str, int fd)
{
int y = 0;

if (!str)
return (0);
while (*str)
{
y += _putfd(*str++, fd);
}
return (y);
}
