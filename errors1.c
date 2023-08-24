#include "Our_Shell.h"

/**
* _erratoi - it converts a string to an integer
* @s: string to be converted
* Return: 0 if there no numbers in string, converted number
*       otherwise -1 on error
*/
int _erratoi(char *s)
{
int y = 0;
unsigned long int result = 0;

if (*s == '+')
s++;  /* TODO: why does this make main return 255? */
for (y = 0;  s[y] != '\0'; y++)
{
if (s[y] >= '0' && s[y] <= '9')
{
result *= 10;
result += (s[y] - '0');
if (result > INT_MAX)
return (-1);
}
else
return (-1);
}
return (result);
}

/**
* print_error - it prints an error message
* @info: parameter & return info struct
* @estr: its the string containing specified error type
* Return: 0 if there is no numbers in string, converted number
*        otherwise -1 on error
*/
void print_error(info_t *info, char *estr)
{
_eputs(info->fname);
_eputs(": ");
_eputs(info->argv[0]);
_eputs(": ");
_eputs(estr);
print_d(info->line_count, STDERR_FILENO);
_eputs(": ");
}

/**
* print_d - its function prints a decimal (integer) number (base 10)
* @input: it isthe input
* @fd: filedescriptor to write to
*
* Return: its number of characters printed
*/
int print_d(int input, int fd)
{
int (*__putchar)(char) = _putchar;
int y, count = 0;
unsigned int _abs_, current;

if (fd == STDERR_FILENO)
__putchar = _eputchar;
if (input < 0)
{
_abs_ = -input;
__putchar('-');
count++;
}
else
_abs_ = input;
current = _abs_;
for (y = 1000000000; y > 1; y /= 10)
{
if (_abs_ / y)
{
__putchar('0' + current / y);
count++;
}
current %= y;
}
__putchar('0' + current);
count++;

return (count);
}

/**
* convert_number - it converts function, a clone of itoa
* @num: its numbers
* @base: the base
* @flags: its the argument flags
*
* Return: strings
*/
char *convert_number(long int num, int base, int flags)
{
static char *array;
static char buffer[50];
char sign = 0;
char *cit;
unsigned long n = num;

if (!(flags & CONVERT_UNSIGNED) && num < 0)
{
n = -num;
sign = '-';

}
array = flags & CONVERT_LOWERCASE ? "0123456789abcdef" : "0123456789ABCDEF";
cit = &buffer[49];
*cit = '\0';

do	{
*--cit = array[n % base];
n /= base;
} while (n != 0);

if (sign)
*--cit = sign;
return (cit);
}

/**
* remove_comments - the function replaces first instance of '#' with '\0'
* @buf: address string to modify
*
* Return: Always (0);
*/
void remove_comments(char *buf)
{
int y;

for (y = 0; buf[y] != '\0'; y++)
if (buf[y] == '#' && (!y || buf[y - 1] == ' '))
{
buf[y] = '\0';
break;
}
}
