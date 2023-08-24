#include "Our_Shell.h"

/**
 * bfree - free the pointer and NULL the address
 * @ptr: address the pointer to frees
 *
 * Return:  if 1 freed, otherwise 0.
 */
int bfree(void **ptr)
{
	if (ptr && *ptr)
	{
		free(*ptr);
		*ptr = NULL;
		return (1);
	}
	return (0);
}
