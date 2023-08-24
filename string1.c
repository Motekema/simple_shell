#include "Our_Shell.h"

/**
* _strcpy - copy the string
* @dest: the destination of
* @src: the source of
*
* Return: point destination
*/
char *_strcpy(char *dest, char *src)
{
int h = 0;

if (dest == src || src == 0)
return (dest);
while (src[h])
{
dest[h] = src[h];
h++;
}
dest[h] = 0;
return (dest);
}

/**
* _strdup - the duplicates a string
* @str:  strings to duplicate
*
* Return: the pointer of the duplicated strings
*/
char *_strdup(const char *str)
{
int length = 0;
char *rest;

if (str == NULL)
return (NULL);
while (*str++)
length++;
rest = malloc(sizeof(char) * (length + 1));
if (!rest)
return (NULL);
for (length++; length--;)
rest[length] = *--str;
return (rest);
}

/**
*_puts - print input strings
*@str:  string to be printed
*
* Return: None
*/
void _puts(char *str)
{
int g = 0;

if (!str)
return;
while (str[g] != '\0')
{
_putchar(str[g]);
g++;
}
}

/**
* _putchar - write the char c to stdout
* @c: The char to print
*
* Return: success 1.
* On error, is -1 returned, and errno is sets appropriately.
*/
int _putchar(char c)
{
static int g;
static char buf[WRITE_BUF_SIZE];

if (c == BUF_FLUSH || g >= WRITE_BUF_SIZE)
{
write(1, buf, g);
g = 0;
}
if (c != BUF_FLUSH)
buf[g++] = c;
return (1);
}
