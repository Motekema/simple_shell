#include "Our_Shell.h"

/**
 **_memset - fill the memory with the constant byte
 *@s: point to the memory area
 *@b: byte to fills *s with
 *@n: amount of bytes be filled
 *Return: (s) pointer to the memory area s
 */
char *_memset(char *s, char b, unsigned int n)
{
	unsigned int h;

	for (h = 0; h < n; h++)
		s[h] = b;
	return (s);
}

/**
 * ffree - free a string of the strings
 * @pp: string of strings
 */
void ffree(char **pp)
{
	char **u = pp;

	if (!pp)
		return;
	while (*pp)
		free(*pp++);
	free(u);
}

/**
 * _realloc - the reallocate a block of memorys
 * @ptr: point to previous mallocated blocks
 * @old_size: byte sizes of previous blocks
 * @new_size: byte sizes of new blocks
 *
 * Return: pointers to the ol'block nameen.
 */
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
	char *l;

	if (!ptr)
		return (malloc(new_size));
	if (!new_size)
		return (free(ptr), NULL);
	if (new_size == old_size)
		return (ptr);

	l = malloc(new_size);
	if (!l)
		return (NULL);

	old_size = old_size < new_size ? old_size : new_size;
	while (old_size--)
		l[old_size] = ((char *)ptr)[old_size];
	free(ptr);
	return (l);
}
