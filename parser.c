#include "Our_Shell.h"

/**
* is_cmd - if determines a file is an executable command
* @info: the infor structure
* @path: path to a  file
*
* Return: 1 if true, 0 otherwise
*/
int is_cmd(info_t *info, char *path)
{
struct stat st;

(void)info;
if (!path || stat(path, &st))
return (0);

if (st.st_mode & S_IFREG)
{
return (1);
}
return (0);
}

/**
* dup_chars - duplicates characte
* @pathstr: The PATH strings
* @start: start index
* @stop: stop index
*
* Return: point to a new buffer
*/
char *dup_chars(char *pathstr, int start, int stop)
{
static char buf[1024];
int i = 0, o = 0;

for(o = 0, i = start; i < stop; i++)
if (pathstr[i] != ':')
buf[o++] = pathstr[i];
buf[o] = 0;
return (buf);
}

/**
* find_path - find this cmd in a PATH strings
* @info:  info structure
* @pathstr: the PATH string
* @cmd: cmd to find
*
* Return: full path of cmd found or NULL
*/
char *find_path(info_t *info, char *pathstr, char *cmd)
{
int j = 0, curr_pos = 0;
char *path;

if (!pathstr)
return (NULL);
if ((_strlen(cmd) > 2) && starts_with(cmd, "./"))
{
if (is_cmd(info, cmd))
return (cmd);
}
while (1)
{
if (!pathstr[j] || pathstr[j] == ':')
{
path = dup_chars(pathstr, curr_pos, j);
if (!*path)
_strcat(path, cmd);
else
{
_strcat(path, "/");
_strcat(path, cmd);
}
if (is_cmd(info, path))
return (path);
if (!pathstr[j])
break;
curr_pos = j;
}
j++;
}
return (NULL);
}
