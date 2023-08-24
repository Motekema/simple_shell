#include "Our_Shell.h"

/**
* get_environ - it returns the string array copy of our environ
* @info: Structures containing potential arguments. Used to maintain
*          constant functions prototype.
* Return: Always (0)
*/
char **get_environ(info_t *info)
{
if (!info->environ || info->env_changed)
{
info->environ = list_to_strings(info->env);
info->env_changed = 0;
}

return (info->environ);
}

/**
* _unsetenv - it Removes an environment variable
* @info: Structures containing potential arguments. Used to maintain
*        constant function prototype.
*  Return: 1 delete, 0 otherwise
* @var: it is the string env var property
*/
int _unsetenv(info_t *info, char *var)
{
list_t *node = info->env;
size_t y = 0;
char *f;

if (!node || !var)
return (0);

while (node)
{
f = starts_with(node->str, var);
if (f && *f == '=')
{
info->env_changed = delete_node_at_index(&(info->env), y);
y = 0;
node = info->env;
continue;
}
node = node->next;
y++;
}
return (info->env_changed);
}

/**
* _setenv - it initialize new environment variable,
*             or modify an existing one
* @info: Structures containing potential arguments. Used to maintain
*        constant function prototype.
* @var: it is the string env var property
* @value: it is the string env var value
*  Return: Always (0)
*/
int _setenv(info_t *info, char *var, char *value)
{
char *buf = NULL;
list_t *node;
char *f;

if (!var || !value)
return (0);

buf = malloc(_strlen(var) + _strlen(value) + 2);
if (!buf)
return (1);
_strcpy(buf, var);
_strcat(buf, "=");
_strcat(buf, value);
node = info->env;
while (node)
{
f = starts_with(node->str, var);
if (f && *f == '=')
{
free(node->str);
node->str = buf;
info->env_changed = 1;
return (0);
}
node = node->next;
}
add_node_end(&(info->env), buf, 0);
free(buf);
info->env_changed = 1;
return (0);
}
