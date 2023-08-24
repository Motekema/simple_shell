#include "Our_Shell.h"

/**
* _Our_env -  prints the current environ
* @info: struct containing potential arguments. constant function prototype.
* Return: Always (0)
*/

int _Our_env(info_t *info)
{
print_list_str(info->env);
return (0);
}

/**
* _getenv - gets value of from environ variable
* @info:  structure containing potential arguments.
* @name: env variable name
*
* Return: value
*/
char *_getenv(info_t *info, const char *name)
{
list_t *node = info->env;
char *h;
while (node)
{h = starts_with(node->str, name);
if (h && *h)
return (h);
node = node->next;
}
return (NULL);
}

/**
* _Our_setenv - Initialize a new environment variable,
* modify an existing one in an environment
* @info: this struct  containing potential arguments.
*  Return: Always 0
*/

int _Our_setenv(info_t *info)
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
* _Our_unsetenv - remove an environment variable into.
* @info: structure containing potential arguments. maintain function prototype.
* Return: Always (0)
*/
int _Our_unsetenv(info_t *info)
{
int p;
if (info->argc == 1)
{
_eputs("Too few arguements.\n");
return (1);
}
for (p = 1; p <= info->argc; p++)
_unsetenv(info, info->argv[p]);
return (0);
}

/**
* populate_env_list - populates env link listed
* @info:  struct containing potential arguments
* Return: Always (0)
*/

int populate_env_list(info_t *info)
{
list_t *node = NULL;
size_t p;

for (p = 0; environ[p]; p++)
add_node_end(&node, environ[p], 0);
info->env = node;
return (0);
}
