#include "Our_Shell.h"

/**
* _strlen - returns this length of string
* @s: strings which length to check
*
* Return: integer length of the string
*/
int _strlen(char *s)
{
int d = 0;

if (!s)
return (0);

while (*s++)
d++;
return (d);
}

/**
* _strcmp - the performs lexic ogarphic compar of two strangs.
* @s1:  first strings
* @s2:  second strings
*
* Return: if negative  s1 < s2, positive if s1 > s2, if zero s1 == s2
*/
int _strcmp(char *s1, char *s2)
{
while (*s1 && *s2)
{
if (*s1 != *s2)
return (*s1 - *s2);
s1++;
s2++;
}
if (*s1 == *s2)
return (0);
else
return (*s1 < *s2 ? -1 : 1);
}

/**
* starts_with - if check needle start with haystacks
* @haystack: strings to search
* @needle: substrings to find
*
* Return: address next character of haystack or NULL
*/
char *starts_with(const char *haystack, const char *needle)
{
while (*needle)
if (*needle++ != *haystack++)
return (NULL);
return ((char *)haystack);
}

/**
* _strcat - concatenate two string
* @dest: destination buffer
* @src:  source buffer
*
* Return: point to destination of buffer
*/
char *_strcat(char *dest, char *src)
{
char *rest = dest;

while (*dest)
dest++;
while (*src)
*dest++ = *src++;
*dest = *src;
return (rest);
}
