#ifndef _OUR_SHELL_H_
#define _OUR_SHELL_H_


char *_getenv(const char *name);
int _setenv(const char *name, const char *value, int overwrite);
int _unsetenv(const char *name);


#endif
