#include "Our_Shell.h"

/**
* hsh - main simple_shell
* @info: the parameter and return info structure
* @av: Argument vector into main()
*
* Return: 0 on successfull, 1 on errors
*/

int hsh(info_t *info, char **av)
{
ssize_t h = 0;
int builtin_rest = 0;
while (h != -1 && builtin_rest != -2)
{
clear_info(info);
if (interactive(info))
_puts("#Motekema&Joshua$ ");
_eputchar(BUF_FLUSH);
h = get_input(info);
if (h != -1)
{
set_info(info, av);
builtin_rest = find_builtin(info);
if (builtin_rest == -1)
find_cmd(info);
}
else if (interactive(info))
_putchar('\n');
free_info(info, 0);
}
write_history(info);
free_info(info, 1);
if (!interactive(info) && info->status)
exit(info->status);
if (builtin_rest == -2)
{
if (info->err_num == -1)
exit(info->status);
exit(info->err_num);
}
return (builtin_rest);
}

/**
* find_builtin - find a builtin command
* @info: the parameter and return info struct
*
* Return: -1 builtin if not found,
* 0 builtin if execute successfull,
* 1 builtin if found but not successfull,
* 2 builtin if signals exit()
*/

int find_builtin(info_t *info)
{
int b, built_in_rest = -1;
builtin_table builtintbl[] = {
{"exit", _Our_exit},
{"env", _Our_env},
{"help", _Our_help},
{"history", _Our_history},
{"setenv", _Our_setenv},
{"unsetenv", _Our_unsetenv},
{"cd", _Our_cd},
{"alias", _Our_alias},
{NULL, NULL}
};

for (b = 0; builtintbl[b].type; b++)
if (_strcmp(info->argv[0], builtintbl[b].type) == 0)
{
info->line_count++;
built_in_rest = builtintbl[b].func(info);
break;
}
return (built_in_rest);
}

/**
* find_cmd - find command in the PATH
* @info: the parameter and return info structure
*
* Return: (void)
*/

void find_cmd(info_t *info)
{
char *path = NULL;
int j, f;
info->path = info->argv[0];
if (info->linecount_flag == 1)
{
info->line_count++;
info->linecount_flag = 0;
}
for (j = 0, f = 0; info->arg[j]; j++)
if (!is_delim(info->arg[j], " \t\n"))
f++;
if (!f)
return;
path = find_path(info, _getenv(info, "PATH="), info->argv[0]);
if (path)
{
info->path = path;
fork_cmd(info);
}
else
{
if ((interactive(info) || _getenv(info, "PATH=")
|| info->argv[0][0] == '/') && is_cmd(info, info->argv[0]))
fork_cmd(info);
else if (*(info->arg) != '\n')
{
info->status = 127;
print_error(info, "not found\n");
}
}
}

/**
* fork_cmd - forks a an exec thread to run cmd
* @info: the parameter & return info struct
*
* Return: void
*/
void fork_cmd(info_t *info)
{
pid_t child_pid;
child_pid = fork();
if (child_pid == -1)
{
/* TODO: PUT ERROR FUNCTION */
perror("Error:");
return;
}
if (child_pid == 0)
{
if (execve(info->path, info->argv, get_environ(info)) == -1)
{
free_info(info, 1);
if (errno == EACCES)
exit(126);
exit(1);
}
/* TODO: PUT ERROR FUNCTION */
}
else
{
wait(&(info->status));
if (WIFEXITED(info->status))
{
info->status = WEXITSTATUS(info->status);
if (info->status == 126)
print_error(info, "Permission denied\n");
}
}
}
