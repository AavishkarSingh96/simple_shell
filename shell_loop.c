#include "shell.h"

/**
 * hsh - main shell loop
 * @info: the parameter & return info struct
 * @law: the argument vector
 *parameter & return info struct argument vector from main
 * Return: 0 on success, 1 on error, or error code
 */
int hsh(info_t *info, char **law)
{
	ssize_t aa = 0;
	int builtin_ret = 0;
/*return info to law*/
	while (aa != -1 && builtin_ret != -2)
	{
		clear_info(info);
		if (interactive(info))
			_puts("$ ");
		_eputchar(BUF_FLUSH);
		aa = get_input(info);
		if (aa != -1)
/*interactive with info*/
		{
			set_info(info, law);
			builtin_ret = find_builtin(info);
			if (builtin_ret == -1)
				find_cmd(info);
		}
		else if (interactive(info))
			_putchar('\n');
		free_info(info, 0);
	}
/*the history to follow*/
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
/*this ends the last section*/
/**
 * find_builtin - finds a builtin command
 * @info: the parameter & return info struct
 *c language used again
 * Return: -1 if builtin not found,
 * 0 success,
 * 1 found but not successful,
 * 2 signals exit()
 */
int find_builtin(info_t *info)
{
	int aa, built_in_ret = -1;
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
/*lists parameters*/
	for (aa = 0; builtintbl[aa].type; aa++)
		if (_strcmp(info->argv[0], builtintbl[aa].type) == 0)
		{
			info->line_count++;
			built_in_ret = builtintbl[aa].func(info);
			break;
		}
	return (built_in_ret);
}
/*thus ends the parameter list*/
/**
 * find_cmd - finds a command in PATH
 * @info: the parameter
 *& return info struct
 * Return: void
 */
void find_cmd(info_t *info)
{
	char *path = NULL;
	int aa, cc;
/*vectors are listed*/
	info->path = info->argv[0];
	if (info->linecount_flag == 1)
	{
		info->line_count++;
		info->linecount_flag = 0;
	}
	for (aa = 0, cc = 0; info->arg[aa]; aa++)
		if (!is_delim(info->arg[aa], " \t\n"))
			cc++;
	if (!cc)
		return;

	path = find_path(info, _getenv(info, "PATH="), info->argv[0]);
	if (path)
	{
		info->path = path;
		fork_cmd(info);
	}
/*next lists if else section*/
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
/*thus ends the path section*/
/**
 * fork_cmd - forks an exec
 * @info: return info struct
 *thread to run cmd
 * Return: void
 */
void fork_cmd(info_t *info)
{
	pid_t child_pid;
/*struct parameter return*/
	child_pid = fork();
	if (child_pid == -1)
/*to do function used*/
	{
		/* TODO: PUT ERROR FUNCTION */
		perror("Error:");
		return;
	}
/*zero selected as value*/
	if (child_pid == 0)
	{
		if (execve(info->path, info->argv, get_environ(info)) == -1)
		{
			free_info(info, 1);
			if (errno == EACCES)
				exit(126);
			exit(1);
		}
		/* TODO: PUT ERROR FUNCTION */
	}
	else
	{
		wait(&(info->status));
		if (WIFEXITED(info->status))
		{
			info->status = WEXITSTATUS(info->status);
			if (info->status == 126)
				print_error(info, "Permission denied\n");
		}
	}
}
/*to do function used*/
/*we are trapped*/
