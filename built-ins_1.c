#include "Our_Shell.h"

/**
* _Our_history - displays history list, one command in line, preceded
* with line numbers, that starting from 0.
* @info: Struct containing potential arg. Used to maintain
* constant function prototype.
* Return: Always (0)
*/
int _Our_history(info_t *info)
{
print_list(info->history);
return (0);
}

/**
* unset_alias -  alias must be string
* @info: parameter structure
* @str: the string is alias
*
* Return: Always 0 on successful, 1 on errors
*/

int unset_alias(info_t *info, char *str)
{
char *d, a;
int rest;
d = _strchr(str, '=');
if (!d)
return (1);
a = *d;
*d = 0;
rest = delete_node_at_index(&(info->alias),
get_node_index(info->alias, node_starts_with(info->alias, str, -1)));
*d = a;
return (rest);
}

/**
* set_alias - alias must be string
* @info: parameter structure
* @str: the string is alias
*
* Return: Always 0 on successfull, 1 on errors
*/

int set_alias(info_t *info, char *str)
{
char *d;
d = _strchr(str, '=');
if (!d)
return (1);
if (!*++d)
return (unset_alias(info, str));
unset_alias(info, str);
return (add_node_end(&(info->alias), str, 0) == NULL);
}

/**
* print_alias - print alias string
* @node: alias node
*
* Return: Always 0 on successfull, 1 on errors
*/

int print_alias(list_t *node)
{
char *d = NULL, *c = NULL;
if (node)
{
d = _strchr(node->str, '=');
for (c = node->str; c <= d; c++)
_putchar(*c);
_putchar('\'');
_puts(d + 1);
_puts("'\n");
return (0);
}
return (1);
}

/**
* _Our_alias - the alias builtin (man alias)
* @info: Struct containing potential arguments. Used the maintain
* constant function prototype.
* Return: Always (0)
*/
int _Our_alias(info_t *info)
{
int z = 0;
char *d = NULL;
list_t *node = NULL;
if (info->argc == 1)
{
node = info->alias;
while (node)
{
print_alias(node);
node = node->next;
}
return (0);
}
for (z = 1; info->argv[z]; z++)
{
d = _strchr(info->argv[z], '=');
if (d)
set_alias(info, info->argv[z]);
else
print_alias(node_starts_with(info->alias, info->argv[z], '='));
}
return (0);
}
