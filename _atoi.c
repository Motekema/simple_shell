#include "Our_Shell.h"

/**
* interactive - returns true if shell is on interactive mode
* @info: structure address
*
* Return: if 1 interactive mode, 0 otherwise
*/
int interactive(info_t *info)
{
return (isatty(STDIN_FILENO) && info->readfd <= 2);
}

/**
* is_delim - if check character is a delimeter
* @c:  char to check
* @delim:  delimeter string
* Return: if 1 true, 0 if false
*/
int is_delim(char c, char *delim)
{
while (*delim)
if (*delim++ == c)
return (1);
return (0);
}

/**
*_isalpha - checker for alphabetic character
*@c: The char to input
*Return: 1 c if is alphabetic, 0 otherwise
*/

int _isalpha(int c)
{
if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
return (1);
else
return (0);
}

/**
*_atoi - convert a string to an integer
*@s:  string to be convert
*Return: 0 no if numbers in string, converted number
*/

int _atoi(char *s)
{
int d, sign = 1, flag = 0, output;
unsigned int result = 0;

for (d = 0;  s[d] != '\0' && flag != 2; d++)
{
if (s[d] == '-')
sign *= -1;

if (s[d] >= '0' && s[d] <= '9')
{
flag = 1;
result *= 10;
result += (s[d] - '0');
}
else if (flag == 1)
flag = 2;
}

if (sign == -1)
output = -result;
else
output = result;

return (output);
}

