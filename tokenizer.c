#include "Our_Shell.h"

/**
* **strtow - split the strings into words. Repeat delimiter and ignored
* @str: input strings
* @d: delimeters strings
* Return: the pointer of an array to strings, or NULL failure
*/

char **strtow(char *str, char *d)
{
int i, z, k, n, numwords = 0;
char **s;

if (str == NULL || str[0] == 0)
return (NULL);
if (!d)
d = " ";
for (i = 0; str[i] != '\0'; i++)
if (!is_delim(str[i], d) && (is_delim(str[i + 1], d) || !str[i + 1]))
numwords++;

if (numwords == 0)
return (NULL);
s = malloc((1 + numwords) * sizeof(char *));
if (!s)
return (NULL);
for (i = 0, z = 0; z < numwords; z++)
{
while (is_delim(str[i], d))
i++;
k = 0;
while (!is_delim(str[i + k], d) && str[i + k])
k++;
s[z] = malloc((k + 1) * sizeof(char));
if (!s[z])
{
for (k = 0; k < z; k++)
free(s[k]);
free(s);
return (NULL);
}
for (n = 0; n < k; n++)
s[z][n] = str[i++];
s[z][n] = 0;
}
s[z] = NULL;
return (s);
}

/**
* **strtow2 - split the strings into word
* @str: input strings
* @d: delimeter
* Return: the pointer to array of string, or NULL failure
*/
char **strtow2(char *str, char d)
{
int i, z, k, n, numwords = 0;
char **s;

if (str == NULL || str[0] == 0)
return (NULL);
for (i = 0; str[i] != '\0'; i++)
if ((str[i] != d && str[i + 1] == d) ||
(str[i] != d && !str[i + 1]) || str[i + 1] == d)
numwords++;
if (numwords == 0)
return (NULL);
s = malloc((1 + numwords) * sizeof(char *));
if (!s)
return (NULL);
for (i = 0, z = 0; z < numwords; z++)
{
while (str[i] == d && str[i] != d)
i++;
k = 0;
while (str[i + k] != d && str[i + k] && str[i + k] != d)
k++;
s[z] = malloc((k + 1) * sizeof(char));
if (!s[z])
{
for (k = 0; k < z; k++)
free(s[k]);
free(s);
return (NULL);
}
for (n = 0; n < k; n++)
s[z][n] = str[i++];
s[z][n] = 0;
}
s[z] = NULL;
return (s);
}
