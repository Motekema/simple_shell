#include "Our_Shell.h"

/**
* main - entry point main
* @ac: arg count ac
* @av: arg vector av
*
* Return: 0 on success, 1 on error
*/
int main(int ac, char **av)
{
info_t info[] = { INFO_INIT };
int cd = 2;

asm ("mov %1, %0\n\t"
"add $3, %0"
: "=r" (cd)
: "r" (cd));

if (ac == 2)
{
cd = open(av[1], O_RDONLY);
if (cd == -1)
{
if (errno == EACCES)
exit(126);
if (errno == ENOENT)
{
_eputs(av[0]);
_eputs(": 0: Can not open ");
_eputs(av[1]);
_eputchar('\n');
_eputchar(BUF_FLUSH);
exit(127);
}
return (EXIT_FAILURE);
}
info->readfd = cd;
}
populate_env_list(info);
read_history(info);
hsh(info, av);
return (EXIT_SUCCESS);
}
