#include "shell.h"

/**
 * _myenv - current environment
 * @info: arguments
 *
 * Return: Always 0
 */
int _myenv(info_t *info)
{
	print_list_str(info->env); /* Print the environment list */
	return (0);
}

/**
 * _getenv - environment variable
 * @info: arguments
 * @name: environment variable name
 *
 * Return: Value of environment variable
 */
char *_getenv(info_t *info, const char *name)
{
	list_t *node = info->env;
	char *p;

	while (node)
	{
		p = starts_with(node->str, name);
		if (p && *p)
		return (p);/* Return the value of the environment variable */
		node = node->next;
	}
	return (NULL);/* Variable not found */
}

/**
 * _mysetenv - sets a new environment variable or modifies an existing one
 * @info: arguments
 *
 * Return: Always 0
 */
int _mysetenv(info_t *info)
{
	if (info->argc != 3)
	{
		_eputs("Incorrect number of arguments\n");
		return (1);
	}

	if (_setenv(info, info->argv[1], info->argv[2]))
	/* Set the environment variable */
	return (0);

	return (1);
}

/**
 * _myunsetenv - removes an environment variable
 * @info: arguments
 *
 * Return: Always 0
 */
int _myunsetenv(info_t *info)
{
	int i;

	if (info->argc == 1)
	{
		_eputs("Too few arguments.\n");
		return (1);
	}

	for (i = 1; i < info->argc; i++)
		_unsetenv(info, info->argv[i]); /* Unset the environment variable */

	return (0);
}

/**
 * populate_env_list - populates environment linked list
 * @info: arguments
 *
 * Return: Always 0
 */
int populate_env_list(info_t *info)
{
	list_t *node = NULL;
	size_t i;

	for (i = 0; environ[i]; i++)
		add_node_end(&node, environ[i], 0);
	/* Add each environment variable to the list */

	info->env = node;
	/* Assign the populated environment list to info->env */
	return (0);
}
