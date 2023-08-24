#include "Our_Shell.h"

/**
* list_len - its determines length of linked list
* @h: it is the pointer to first node
*
* Return: it is the size of list
*/
size_t list_len(const list_t *h)
{
size_t y = 0;

while (h)
{
h = h->next;
y++;
}
return (y);
}

/**
* list_to_strings - it returns array of strings of the list->str
* @head: it is the pointer to first node
*
* Return: it is an array of strings
*/
char **list_to_strings(list_t *head)
{
list_t *node = head;
size_t y = list_len(head), l;
char **strs;
char *str;

if (!head || !y)
return (NULL);
strs = malloc(sizeof(char *) * (y + 1));
if (!strs)
return (NULL);
for (y = 0; node; node = node->next, y++)
{
str = malloc(_strlen(node->str) + 1);
if (!str)
{
for (j = 0; l < y; l++)
free(strs[l]);
free(strs);
return (NULL);
}

str = _strcpy(str, node->str);
strs[y] = str;
}
strs[y] = NULL;
return (strs);
}


/**
* print_list - it prints elements of a list_t linked list
* @h: it is the pointer to first node
*
* Return: it is the size of list
*/
size_t print_list(const list_t *h)
{
size_t y = 0;

while (h)
{
_puts(convert_number(h->num, 10, 0));
_putchar(':');
_putchar(' ');
_puts(h->str ? h->str : "(nil)");
_puts("\n");
h = h->next;
y++;
}
return (y);
}

/**
* node_starts_with - it returns node string starts with prefix
* @node: it is the pointer to list head
* @prefix: it is the string to match
* @c: it is the next character after prefix to match
*
* Return: matchs node or null
*/
list_t *node_starts_with(list_t *node, char *prefix, char c)
{
char *f = NULL;

while (node)
{
f = starts_with(node->str, prefix);
if (f && ((c == -1) || (*f == c)))
return (node);
node = node->next;
}
return (NULL);
}

/**
* get_node_index - it gets index of node
* @head: it is the pointer to list head
* @node: it is the pointer to the node
*
* Return: the index of node or -1
*/
ssize_t get_node_index(list_t *head, list_t *node)
{
size_t y = 0;

while (head)
{
if (head == node)
return (y);
head = head->next;
y++;
}
return (-1);
}
