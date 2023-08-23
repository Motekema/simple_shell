#include "Our_Shell.h"

/**
* dfree -NULLs the address and frees pointer
* @potr: address of the pointer to free
*
* Return: 1 freed, otherwise 0.
*/

int dfree(void **potr)
{
if (potr && *potr)
{
free(*potr);
*potr = NULL;
return (1);
}
return (0);
}
