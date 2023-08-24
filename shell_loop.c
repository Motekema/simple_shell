#include "Our_Shell.h"

/**
 * hsh - shell loop
 * @info: a parameter & return infor struct
 * @av:  arguments vector from main()
 *
 * Return: 0 on successful, 1 on errors, or error codes
 */
int hsh(info_t *info, char **av)
{
	ssize_t j = 0;
	int builtin_ret = 0;

	while (j != -1 && builtin_ret != -2)
	{
		clear_info(info);
		if (interactive(info))
			_puts("$ ");
		_eputchar(BUF_FLUSH);
		j = get_input(info);
		if (j != -1)
		{
			set_info(info, av);
			builtin_ret = find_builtin(info);
			if (builtin_ret == -1)
				find_cmd(info);
		}
		else if (interactive(info))
			_putchar('\n');
		free_info(info, 0);
	}
	write_history(info);
	free_info(info, 1);
	if (!interactive(info) && info->status)
		exit(info->status);
	if (builtin_ret == -2)
	{
		if (info->err_num == -1)
			exit(info->status);
		exit(info->err_num);
	}
	return (builtin_ret);
}

/**
 * find_builtin - find a builtin commands
 * @info:  parameter & return infor structure
 *
 * Return: if -1  builtin not found,
 *			0 if builtin execute successful,
 *			1 if builtin found not successfully,
 *			-2 if builtin signal exit()
 */
int find_builtin(info_t *info)
{
	int f, built_in_ret = -1;
	builtin_table builtintbl[] = {
		{"exit", _myexit},
		{"env", _myenv},
		{"help", _myhelp},
		{"history", _myhistory},
		{"setenv", _mysetenv},
		{"unsetenv", _myunsetenv},
		{"cd", _mycd},
		{"alias", _myalias},
		{NULL, NULL}
	};

	for (f = 0; builtintbl[f].type; f++)
		if (_strcmp(info->argv[0], builtintbl[f].type) == 0)
		{
			info->line_count++;
			built_in_ret = builtintbl[f].func(info);
			break;
		}
	return (built_in_ret);
}

/**
 * find_cmd - find command in PATHs
 * @info: parameter & return info structure
 *
 * Return: void
 */
void find_cmd(info_t *info)
{
	char *path = NULL;
	int j, k;

	info->path = info->argv[0];
	if (info->linecount_flag == 1)
	{
		info->line_count++;
		info->linecount_flag = 0;
	}
	for (j = 0, k = 0; info->arg[j]; j++)
		if (!is_delim(info->arg[j], " \t\n"))
			k++;
	if (!k)
		return;

	path = find_path(info, _getenv(info, "PATH="), info->argv[0]);
	if (path)
	{
		info->path = path;
		fork_cmd(info);
	}
	else
	{
		if ((interactive(info) || _getenv(info, "PATH=")
			|| info->argv[0][0] == '/') && is_cmd(info, info->argv[0]))
			fork_cmd(info);
		else if (*(info->arg) != '\n')
		{
			info->status = 127;
			print_error(info, "not found\n");
		}
	}
}

/**
 * fork_cmd - forks an exec thread to runs cmd
 * @info:  parameter & return infor structure
 *
 * Return: Void
 */
void fork_cmd(info_t *info)
{
	pid_t child_pid;

	child_pid = fork();
	if (child_pid == -1)
	{
		/* TODO: PUT ERRORs FUNCTION */
		perror("Error:");
		return;
	}
	if (child_pid == 0)
	{
		if (execve(info->path, info->argv, get_environ(info)) == -1)
		{
			free_info(info, 1);
			if (errno == EACCES)
				exit(126);
			exit(1);
		}
		/* TODO: PUT ERRORs FUNCTION */
	}
	else
	{
		wait(&(info->status));
		if (WIFEXITED(info->status))
		{
			info->status = WEXITSTATUS(info->status);
			if (info->status == 126)
				print_error(info, "Permission is denied\n");
		}
	}
}
