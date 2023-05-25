#include "shell.h"

/**
 * _myhistory - displays the history list
 * @info: Structure containing potential arguments
 *
 * Return: Always 0
 */
int _myhistory(info_t *info)
{
	print_list(info->history); /* Print the history list */
	return (0);
}

/**
 * unset_alias - removes an alias from the alias list
 * @info: parameter struct
 * @str: the alias string
 *
 * Return: Always 0 on success, 1 on error
 */
int unset_alias(info_t *info, char *str)
{
	char *p, c;
	int ret;

	p = _strchr(str, '=');
	if (!p)
		return (1);

	c = *p;
	*p = 0;/* Terminate the string at the position of '=' */
	/* Delete the node with matching alias from the alias list */
	ret = delete_node_at_index(&(info->alias),
	get_node_index(info->alias, node_starts_with(info->alias, str, -1)));
	*p = c;/* Restore the original string */
	return (ret);
}

/**
 * set_alias - sets an alias in the alias list
 * @info: parameter struct
 * @str: the alias string
 *
 * Return: Always 0 on success, 1 on error
 */
int set_alias(info_t *info, char *str)
{
	char *p;

	p = _strchr(str, '=');
	if (!p)
		return (1);

	if (!*++p)
		return (unset_alias(info, str)); /* If value is empty, unset the alias */

	unset_alias(info, str); /* Remove any existing alias with the same name */
	return (add_node_end(&(info->alias), str, 0) == NULL);
	/* Add the new alias to the end of the alias list */
}

/**
 * print_alias - prints an alias string
 * @node: the alias node
 *
 * Return: Always 0 on success, 1 on error
 */
int print_alias(list_t *node)
{
	char *p = NULL, *a = NULL;

	if (node)
	{
		p = _strchr(node->str, '=');
		for (a = node->str; a <= p; a++)
			_putchar(*a); /* Print the alias name */
		_putchar('\'');
		_puts(p + 1); /* Print the alias value */
		_puts("'\n");
		return (0);
	}
	return (1);
}

/**
 * _myalias - mimics the alias builtin
 * @info: Structure containing potential arguments
 *
 * Return: Always 0
 */
int _myalias(info_t *info)
{
	int i = 0;
	char *p = NULL;
	list_t *node = NULL;

	if (info->argc == 1) /* If no arguments provided, print all aliases */
	{
		node = info->alias;
		while (node)
		{
			print_alias(node);
			node = node->next;
		}
		return (0);
	}

	for (i = 1; info->argv[i]; i++)
	{
		p = _strchr(info->argv[i], '=');
		if (p)/* If the argument contains "=", set the alias */
		set_alias(info, info->argv[i]);
		else/*If the argument does not contain "="*/
		/*print the corresponding alias*/
	print_alias(node_starts_with(info->alias, info->argv[i], '='));
	}

	return (0);
}
