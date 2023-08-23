#include "Our_Shell.h"

/**
* _Our_exit - exits shell
* @info: Structure containing arguments. Used to maintain function prototype
* constant function prototype.
* Return: with given exit status return exit
* (0) if info.argv[0] != "exit"
*/

int _Our_exit(info_t *info)
{
int exit_on_checker;
if (info->argv[1]) /* If there is exit arguement */
{
exit_on_checker = _erratoi(info->argv[1]);
if (exit_on_checker == -1)
{
info->status = 2;
print_error(info, "Unknown number: ");
_eputs(info->argv[1]);
_eputchar('\n');
return (1);
}
info->err_num = _erratoi(info->argv[1]);
return (-2);
}
info->err_num = -1;
return (-2);
}
/**
* _Our_cd -  this changes current directory
* @info: the structure containing potential arguments.for prototype
* Return: Always (0)
*/
int _Our_cd(info_t *info)
{
char *v, *dir, buffer[1024];
int chdir_ret;
v = getcwd(buffer, 1024);
if (!v)
_puts("TODO: >>getcwd failure msg here<<\n");
if (!info->argv[1])
{
dir = _getenv(info, "DESKTOP=");
if (!dir)
chdir_ret = /* TODO: what should this _be? */
chdir((dir = _getenv(info, "PWD=")) ? dir : "/");
else
chdir_ret = chdir(dir);
}
else if (_strcmp(info->argv[1], "-") == 0)
{
if (!_getenv(info, "OLDPWD="))
{
_puts(v);
_putchar('\n');
return (1);
}
_puts(_getenv(info, "OLDPWD=")), _putchar('\n');
chdir_ret = /* TODO: what should this _be? */
chdir((dir = _getenv(info, "OLDPWD=")) ? dir : "/");
}
else
chdir_ret = chdir(info->argv[1]);
if (chdir_ret == -1)
{
print_error(info, "can not cd into ");
_eputs(info->argv[1]), _eputchar('\n');
}
else
{
_setenv(info, "OLDPWD", _getenv(info, "PWD="));
_setenv(info, "PWD", getcwd(buffer, 1024));
}
return (0);
}

/**
* _Our_help - changes current directory of the process
* @info: Structure containing potential arguments. Used to maintain
* constant function prototype.
* Return: Always (0)
*/

int _Our_help(info_t *info)
{
char **arg_arrays;
arg_arrays = info->argv;
_puts("help call works. Function not implemented \n");
if (0)
_puts(*arg_arrays);
return (0);
}
