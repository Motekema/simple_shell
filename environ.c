#include "Our_Shell.h"

/**
* _myenv - it prints current environment
* @info: Structure containing the potential arguments. Used to maintain
*          constant function prototype.
* Return: Always (0)
*/
int _myenv(info_t *info)
{
print_list_str(info->env);
return (0);
}

/**
* _getenv - it gets value of an environ variable
* @info: Structure containing the potential arguments. Used to maintain
* @name: env var names
*
* Return: the value
*/
char *_getenv(info_t *info, const char *name)
{
list_t *node = info->env;
char *f;

while (node)
{
f = starts_with(node->str, name);
if (f && *f)
return (f);
node = node->next;
}
return (NULL);
}

/**
* _mysetenv - Initialize new environment variable,
*             or modify a existing one
* @info: Structure containing the potential arguments. Used to maintain
*        constant function prototype.
*  Return: Always (0)
*/
int _mysetenv(info_t *info)
{
if (info->argc != 3)
{
_eputs("Incorrect number of arguements\n");
return (1);
}
if (_setenv(info, info->argv[1], info->argv[2]))
return (0);
return (1);
}

/**
* _myunsetenv - it Remove an environment variable
* @info: Structure containing the potential arguments. Used to maintain
*        constant function prototype.
*  Return: Always (0)
*/
int _myunsetenv(info_t *info)
{
int y;

if (info->argc == 1)
{
_eputs("Too few arguements.\n");
return (1);
}
for (y = 1; y <= info->argc; y++)
_unsetenv(info, info->argv[y]);

return (0);
}

/**
* populate_env_list - it populates env linked list
* @info: Structure containing the potential arguments. Used to maintain
*          constant function prototype.
* Return: Always (0)
*/
int populate_env_list(info_t *info)
{
list_t *node = NULL;
size_t y;

for (y = 0; environ[y]; y++)
add_node_end(&node, environ[y], 0);
info->env = node;
return (0);
}
