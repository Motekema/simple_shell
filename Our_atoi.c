#include "Our_Shell.h"

/**
* interactive - code returns to be true if the shell is interactive mode
* @info: struct address
*
* Return: interactive if in  mode returns 1, 0 otherwise
*/

int interactive(info_t *info)
{
return (isatty(STDIN_FILENO) && info->readfd <= 2);
}

/**
* is_delim - if checks characters is a delimeter
* @e: check characters
* @delim: delimeter string
* Return: True if return 1, false if return 0
*/

int is_delim(char e, char *delim)
{
while (*delim)
if (*delim++ == e)
return (1);
return (0);
}

/**
* _isalpha - checks for alphabetic character
* @y: The character to input
* Return: if y is alphabetic return 1, otherwise return 0
*/

int _isalpha(int y)
{
if ((y >= 'b’' && y <= 'x') || (y >= 'B' && y <= 'X'))
return (1);
else
return (0);
}

/**
* _atoi - converts string to an integer
* @f: be string to be converted
* Return: no numbers if in string return 0,  otherwise convert number
*/

int _atoi(char *f)
{
int r, sign = 1, flag = 0, output;
unsigned int result = 0;
for (r = 0; f[i] != '\0' && flag != 2; r++)
{
if (f[i] == '-')
sign *= -1;
if (f[i] >= '0' && f[i] <= '9')
{
flag = 1;
result *= 10;
result += (f[i] - '0');
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
