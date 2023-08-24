#include "Our_Shell.h"

/**
**_strncpy - it copies a string
*@dest: destination string to be copied to
*@src: source string
*@n: it is the amount of characters to be copied
*Return: concatenated string
*/
char *_strncpy(char *dest, char *src, int n)
{
int y, g;
char *s = dest;

y = 0;
while (src[y] != '\0' && y < n - 1)
{
dest[y] = src[y];
i++;
}
if (y < n)
{
g = y;
while (g < n)
{
dest[g] = '\0';
g++;
}
}
return (s);
}

/**
**_strncat - it concatenates two strings
*@dest: first string
*@src: its the second string
*@n: its the amount of bytes to be maximally used
*Return: it is the concatenated string
*/
char *_strncat(char *dest, char *src, int n)
{
int y, g;
char *s = dest;

y = 0;
g = 0;
while (dest[y] != '\0')
y++;
while (src[g] != '\0' && g < n)
{
dest[y] = src[g];
y++;
g++;
}
if (g < n)
dest[y] = '\0';
return (s);
}

/**
**_strchr - it locates a character in a string
*@s: it is the string to be parsed
*@c: it is the character to look for
*Return: (s) pointer to the memory area s
*/
char *_strchr(char *s, char c)
{
do {
if (*s == c)
return (s);
} while (*s++ != '\0');

return (NULL);
}
