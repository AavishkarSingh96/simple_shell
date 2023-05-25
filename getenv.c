#include "shell.h"

/**
 * get_environ - returns the string array copy of our environment
 * @info: potential arguments
 * Return: A pointer to the string array
 */
char **get_environ(info_t *info)
{
/* Check if the environ has changed or not */
if (!info->environ || info->env_changed)
{
/* Convert the linked list to a string array */
info->environ = list_to_strings(info->env);
info->env_changed = 0;
}
return (info->environ);
}

/**
 * _unsetenv - Remove an environment variable
 * @info: potential arguments
 * @var: environment variable
 * Return: 1 if the variable was deleted, 0 otherwise
 */
int _unsetenv(info_t *info, char *var)
{
list_t *node = info->env;
size_t i = 0;
char *p;

if (!node || !var)
return (0);
while (node)
{
p = starts_with(node->str, var);
if (p && *p == '=')
{
/* Delete the node at the current index */
info->env_changed = delete_node_at_index(&(info->env), i);
i = 0;
node = info->env;
continue;
}
node = node->next;
i++;
}
return (info->env_changed);
}

/**
 * _setenv - Initialize a new environment variable,or edits existing one
 * @info: arguments.
 * @var: environment variable
 * @value: value of the environment variable
 * Return: Always 0
 */
int _setenv(info_t *info, char *var, char *value)
{
char *buf = NULL;
list_t *node;
char *p;

if (!var || !value)
return (0);

/* Allocate memory for the new environment variable string */
buf = malloc(_strlen(var) + _strlen(value) + 2);
if (!buf)
return (1);

/* Concatenate the variable and value with '=' separator */
_strcpy(buf, var);
_strcat(buf, "=");
_strcat(buf, value);

node = info->env;
while (node)
{
p = starts_with(node->str, var);
if (p && *p == '=')
{
/* Modify the existing environment variable */
free(node->str);
node->str = buf;
info->env_changed = 1;
return (0);
}
node = node->next;
}

/* Add a new environment variable to the end of the list */
add_node_end(&(info->env), buf, 0);
free(buf);
info->env_changed = 1;
return (0);
}
