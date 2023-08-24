#include "Our_Shell.h"

/**
* add_node - it add node to start of the list
* @head: it is the address of pointer to head node
* @str: its a string field of node
* @num: it is the node index used by history
*
* Return: the size of list
*/
list_t *add_node(list_t **head, const char *str, int num)
{
list_t *new_head;

if (!head)
return (NULL);
new_head = malloc(sizeof(list_t));
if (!new_head)
return (NULL);
_memset((void *)new_head, 0, sizeof(list_t));
new_head->num = num;
if (str)
{
new_head->str = _strdup(str);
if (!new_head->str)
{
free(new_head);
return (NULL);
}
}
new_head->next = *head;
*head = new_head;
return (new_head);
}

/**
* add_node_end - it add node to end of the list
* @head: it is an address a pointer to head node
* @str: it is the string field of node
* @num: it is the node index used by history
*
* Return: the size of list
*/
list_t *add_node_end(list_t **head, const char *str, int num)
{
list_t *new_node, *node;

if (!head)
return (NULL);

node = *head;
new_node = malloc(sizeof(list_t));
if (!new_node)
return (NULL);
_memset((void *)new_node, 0, sizeof(list_t));
new_node->num = num;
if (str)
{
new_node->str = _strdup(str);
if (!new_node->str)
{
free(new_node);
return (NULL);
}
}
if (node)
{
while (node->next)
node = node->next;
node->next = new_node;
}
else
*head = new_node;
return (new_node);
}

/**
* print_list_str - it prints only string element of list_t linked list
* @h: it is a pointer to first node
*
* Return: the size of list
*/
size_t print_list_str(const list_t *h)
{
size_t y = 0;

while (h)
{
_puts(h->str ? h->str : "(nil)");
_puts("\n");
h = h->next;
y++;
}
return (y);
}

/**
* delete_node_at_index - it deletes node at given index
* @head: it is the address of pointer to first node
* @index:it is the  index of node to delete
*
* Return: 1 success, 0 failure
*/
int delete_node_at_index(list_t **head, unsigned int index)
{
list_t *node, *prev_node;
unsigned int y = 0;

if (!head || !*head)
return (0);

if (!index)
{
node = *head;
*head = (*head)->next;
free(node->str);
free(node);
return (1);
}
node = *head;
while (node)
{
if (y == index)
{
prev_node->next = node->next;
free(node->str);
free(node);
return (1);
}
y++;
prev_node = node;
node = node->next;
}
return (0);
}

/**
* free_list - it frees all nodes of list
* @head_ptr: it is the address of pointer to head node
*
* Return: Void
*/
void free_list(list_t **head_ptr)
{
list_t *node, *next_node, *head;

if (!head_ptr || !*head_ptr)
return;
head = *head_ptr;
node = head;
while (node)
{
next_node = node->next;
free(node->str);
free(node);
node = next_node;
}
*head_ptr = NULL;
}
