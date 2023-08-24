#include "Our_Shell.h"

/**
* is_chain - if test the current char in buffer is an chain delimeter
* @info: parameter structure
* @buf: the character buffer
* @p: address the current position of buf
*
* Return: if 1  chain delimeter, 0 otherwise
*/
int is_chain(info_t *info, char *buf, size_t *p)
{
size_t h = *p;

if (buf[h] == '|' && buf[h + 1] == '|')
{
buf[h] = 0;
h++;
info->cmd_buf_type = CMD_OR;
}
else if (buf[h] == '&' && buf[h + 1] == '&')
{
buf[h] = 0;
h++;
info->cmd_buf_type = CMD_AND;
}
else if (buf[h] == ';') /* found end of the command */
{
buf[h] = 0; /* replace the semicolon with null */
info->cmd_buf_type = CMD_CHAIN;
}
else
return (0);
*p = h;
return (1);
}

/**
* check_chain - check that should continue chaining based on the last status
* @info: the parameter structure
* @buf: char buffer
* @p: address of the currents position in buf
* @i: starting position of buf
* @len: length of the buf
*
* Return: void
*/
void check_chain(info_t *info, char *buf, size_t *p, size_t i, size_t len)
{
size_t h = *p;

if (info->cmd_buf_type == CMD_AND)
{
if (info->status)
{
buf[i] = 0;
h = len;
}
}
if (info->cmd_buf_type == CMD_OR)
{
if (!info->status)
{
buf[i] = 0;
h = len;
}
}

*p = h;
}

/**
* replace_alias - replaces an aliase in the tokenized strings
* @info: parameter structure
*
* Return:  if 1 replaced, 0 otherwise
*/
int replace_alias(info_t *info)
{
int z;
list_t *node;
char *p;

for (z = 0; z < 10; z++)
{
node = node_starts_with(info->alias, info->argv[0], '=');
if (!node)
return (0);
free(info->argv[0]);
p = _strchr(node->str, '=');
if (!p)
return (0);
p = _strdup(p + 1);
if (!p)
return (0);
info->argv[0] = p;
}
return (1);
}

/**
* replace_vars - replaces vars on the tokenized strings
* @info: the parameter structure
*
* Return: if 1 replaced, 0 otherwise
*/
int replace_vars(info_t *info)
{
int y = 0;
list_t *node;

for (y = 0; info->argv[y]; y++)
{
if (info->argv[y][0] != '$' || !info->argv[y][1])
continue;

if (!_strcmp(info->argv[y], "$?"))
{
replace_string(&(info->argv[y]),
_strdup(convert_number(info->status, 10, 0)));
continue;
}
if (!_strcmp(info->argv[y], "$$"))
{
replace_string(&(info->argv[y]),
_strdup(convert_number(getpid(), 10, 0)));
continue;
}
node = node_starts_with(info->env, &info->argv[y][1], '=');
if (node)
{
replace_string(&(info->argv[y]),
_strdup(_strchr(node->str, '=') + 1));
continue;
}
replace_string(&info->argv[y], _strdup(""));

}
return (0);
}

/**
* replace_string - replaces strings
* @old: address the old string
* @new: new strings
*
* Return: if 1 replaced, 0 otherwise
*/
int replace_string(char **old, char *new)
{
free(*old);
*old = new;
return (1);
}
