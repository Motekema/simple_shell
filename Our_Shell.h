#ifndef _OUR_SHELL_H_
#define _OUR_SHELL_H_

int main(void);
int main(int ac, char **av);
int main(int ac, char **av, char **env);
int main(int ac, char **av);
char *_getenv(const char *name);
int _setenv(const char *name, const char *value, int overwrite);
int _unsetenv(const char *name);


#endif
