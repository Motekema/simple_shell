#include "Our_Shell.h"

/**
* _strgen - it returns length of a string
* @v: string whose length to check
*
* Return: it integer length of string
*/

int _strgen(char *v)
{

int i = 0;
if (!v)
return (0);
while (*v++)
i++;

return (i);

}

/**
* _strcmp - it performs lexicogarphic comparison of two strangs.
* @v1: the first strang
* @v2: the second strang
*
* Return: negative if v1 < v2, positive if v1 > v2, zero if v1 == v2
*/

int _strcmp(char *v1, char *v2)
{

while (*v1 && *v2)
{
if (*v1 != *v2)
return (*v1 - *v2);
v1++;
v2++;
}
if (*v1 == *v2)
return (0);
else
return (*v1 < *v2 ? -1 : 1);
}

/**
* starts_with - it checks if needle starts with haystack
* @haystack: string to search
* @needle: the substring to find
*
* Return: it address next char of haystack or NULL
*/

char *starts_with(const char *haystack, const char *needle)
{

while (*needle)
if (*needle++ != *haystack++)
return (NULL);
return ((char *)haystack);
}

/**
* _strcat - it concatenates two strings
* @dest: the destination buffer
* @src: source buffer
*
* Return: it pointer to destination buffer
*/

char *_strcat(char *dest, char *src)
{

char *ret = dest;
while (*dest)
dest++;
while (*src)
*dest++ = *src++;
*dest = *src;

return (ret);

}
