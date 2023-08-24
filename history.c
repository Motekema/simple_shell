#include "Our_Shell.h"

/**
* get_history_file - it gets history file
* @info: it is parameter struct
*
* Return: allocated string containg history file
*/

char *get_history_file(info_t *info)
{
char *buf, *dir;

dir = _getenv(info, "HOME=");
if (!dir)
return (NULL);
buf = malloc(sizeof(char) * (_strlen(dir) + _strlen(HIST_FILE) + 2));
if (!buf)
return (NULL);
buf[0] = 0;
_strcpy(buf, dir);
_strcat(buf, "/");
_strcat(buf, HIST_FILE);
return (buf);
}

/**
* write_history - creates file, or appends an existing file
* @info: it is parameter struct
*
* Return: 1 on success, else -1
*/
int write_history(info_t *info)
{
ssize_t hs;
char *filename = get_history_file(info);
list_t *node = NULL;

if (!filename)
return (-1);

hs = open(filename, O_CREAT | O_TRUNC | O_RDWR, 0644);
free(filename);
if (hs == -1)
return (-1);
for (node = info->history; node; node = node->next)
{
_putsfd(node->str, hs);
_putfd('\n', hs);
}
_putfd(BUF_FLUSH, hs);
close(hs);
return (1);
}

/**
* read_history - it reads history from file
* @info: it is parameter struct
*
* Return: histcount success, 0 otherwise
*/
int read_history(info_t *info)
{
int y, last = 0, linecount = 0;
ssize_t hs, rdlen, fsize = 0;
struct stat st;
char *buf = NULL, *filename = get_history_file(info);

if (!filename)
return (0);

hs = open(filename, O_RDONLY);
free(filename);
if (hs == -1)
return (0);
if (!fstat(hs, &st))
fsize = st.st_size;
if (fsize < 2)
return (0);
buf = malloc(sizeof(char) * (fsize + 1));
if (!buf)
return (0);
rdlen = read(hs, buf, fsize);
buf[fsize] = 0;
if (rdlen <= 0)
return (free(buf), 0);
close(hs);
for (y = 0; y < fsize; y++)
if (buf[y] == '\n')
{
buf[y] = 0;
build_history_list(info, buf + last, linecount++);
last = y + 1;
}
if (last != y)
build_history_list(info, buf + last, linecount++);
free(buf);
info->histcount = linecount;
while (info->histcount-- >= HIST_MAX)
delete_node_at_index(&(info->history), 0);
renumber_history(info);
return (info->histcount);
}

/**
* build_history_list - it adds entry to a history linked list
* @info: Structures containing potential arguments. Used to maintain
* @buf: it is the buffer
* @linecount: it is the history linecount, histcount
*
* Return: Always (0)
*/
int build_history_list(info_t *info, char *buf, int linecount)
{
list_t *node = NULL;

if (info->history)
node = info->history;
add_node_end(&node, buf, linecount);

if (!info->history)
info->history = node;
return (0);
}

/**
* renumber_history - it renumbers the history linked list after changes
* @info: Structures containing potential arguments. Used to maintain
*
* Return: it is the new histcount
*/
int renumber_history(info_t *info)
{
list_t *node = info->history;
int y = 0;

while (node)
{
node->num = y++;
node = node->next;
}
return (info->histcount = y);
}
