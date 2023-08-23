#include "Our_Shell.h"

/**
* main - entry point
* @cc: arg count
* @so: arg vector
*
* Return: 1 error, 0 success
*/

int main(int cc, char **so)

{
info_t info[] = { (info_t)INFO_INIT };
int cd = 2;
asm ("mov %1, %0\n\t"

"add $3, %0"

: "=r" (cd)

: "r" (cd));

if (cc == 2)
{
cd = open(so[1], O_RDONLY);
if (cd == -1)
{
if (errno == EACCES)
exit(126);
if (errno == ENOENT)
{
_eputs(so[0]);
_eputs(": 0: Can't open ");
_eputs(so[1]);
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
hsh(info, so);
return (EXIT_SUCCESS);
}
