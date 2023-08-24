#include "Our_Shell.h"

/**
* input_buf - it buffers chained commands
* @info: it is parameter struct
* @buf: it is the address of buffer
* @len: it is the address of len var
*
* Return: bytes read
*/
ssize_t input_buf(info_t *info, char **buf, size_t *len)
{
ssize_t v = 0;
size_t len_p = 0;

if (!*len) /* if nothing left in the buffer, fill it */
{
/*bfree((void **)info->cmd_buf);*/
free(*buf);
*buf = NULL;
signal(SIGINT, sigintHandler);
#if USE_GETLINE
v = getline(buf, &len_p, stdin);
#else
v = _getline(info, buf, &len_p);
#endif
if (v > 0)
{
if ((*buf)[v - 1] == '\n')
{
(*buf)[v - 1] = '\0'; /* remove trailing newline */
v--;
}
info->linecount_flag = 1;
remove_comments(*buf);
build_history_list(info, *buf, info->histcount++);
/* if (_strchr(*buf, ';')) is this a command chain? */
{
*len = v;
info->cmd_buf = buf;
}
}
}
return (v);
}

/**
* get_input - it gets a line minus the newline
* @info: it is the parameter struct
*
* Return: bytes read
*/
ssize_t get_input(info_t *info)
{
static char *buf; /* the ';' command chain buffer */
static size_t y, j, len;
ssize_t v = 0;
char **buf_p = &(info->arg), *p;

_putchar(BUF_FLUSH);
v = input_buf(info, &buf, &len);
if (v == -1) /* EOF */
return (-1);
if (len)	/* we have commands left in the chain buffer */
{
j = y; /* init new iterator to current buf position */
p = buf + y; /* get pointer for return */

check_chain(info, buf, &j, y, len);
while (j < len) /* iterate to semicolon or end */
{
if (is_chain(info, buf, &j))
break;
j++;
}

y = j + 1; /* increment past nulled ';'' */
if (y >= len) /* reached end of buffer? */
{
y = len = 0; /* reset position and length */
info->cmd_buf_type = CMD_NORM;
}

*buf_p = p; /* pass back pointer to current command position */
return (_strlen(p)); /* return length of current command */
}

*buf_p = buf; /* else not a chain, pass back buffer from _getline() */
return (v); /* return length of buffer from _getline() */
}

/**
* read_buf - it reads a buffer
* @info: it is a parameter struct
* @buf: it is a buffer
* @i: it is the size
*
* Return: v
*/
ssize_t read_buf(info_t *info, char *buf, size_t *i)
{
ssize_t v = 0;

if (*i)
return (0);
v = read(info->readfd, buf, READ_BUF_SIZE);
if (v >= 0)
*i = v;
return (v);
}

/**
* _getline - it gets the next line of input from STDIN
* @info: it is the parameter struct
* @ptr:  address of the pointer to buffer, preallocated or NULL
* @length: it is size of the preallocated ptr buffer if not NULL
*
* Return: z
*/
int _getline(info_t *info, char **ptr, size_t *length)
{
static char buf[READ_BUF_SIZE];
static size_t y, len;
size_t k;
ssize_t v = 0, z = 0;
char *p = NULL, *new_p = NULL, *c;

p = *ptr;
if (p && length)
z = *length;
if (i == len)
y = len = 0;

v = read_buf(info, buf, &len);
if (v == -1 || (r == 0 && len == 0))
return (-1);

c = _strchr(buf + y, '\n');
k = c ? 1 + (unsigned int)(c - buf) : len;
new_p = _realloc(p, z, z ? z + k : k + 1);
if (!new_p) /* MALLOC FAILURE! */
return (p ? free(p), -1 : -1);

if (z)
_strncat(new_p, buf + y, k - y);
else
_strncpy(new_p, buf + y, k - y + 1);

z += k - y;
y = k;
p = new_p;

if (length)
*length = z;
*ptr = p;
return (z);
}

/**
* sigintHandler - it is the blocks ctrl-C
* @sig_num: its signal number
*
* Return: Void
*/
void sigintHandler(__attribute__((unused))int sig_num)
{
_puts("\n");
_puts("$ ");
_putchar(BUF_FLUSH);
}
