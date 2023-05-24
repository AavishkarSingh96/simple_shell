#include "shell.h"

/**
 * get_environ - returns the string array copy of our environment
 * @info: arguments.
 *
 * Return: The string array copy of the environment variables.
 */
char **get_environ(info_t *info)
{
if (!info->environ || info->env_changed)
{
info->environ = list_to_strings(info->env);
info->env_changed = 0;
}
return (info->environ);
/*checks if environ of info structure is null or if env_changed is non 0*/
/*if either is true, environment variables need to be updated*/
/*In the if statement,environment variables is converted to array of strings*/
}

/**
 * _unsetenv - Remove an environment variable
 * @info: Structure containing arguments.
 * @var: The string env var property.
 *
 * Return: 1 on delete, 0 otherwise.
 */
int _unsetenv(info_t *info, char *var)
{
list_t *node = info->env;
size_t x = 0;
char *p;

if (!node || !var)
return (0);
while (node)
{
p = starts_with(node->str, var);
if (p && *p == '=')
{
info->env_changed = delete_node_at_index(&(info->env), x);
x = 0;
node = info->env;
continue;
}
node = node->next;
x++;
}
return (info->env_changed);
/*Function sets up a pointer node to the env member of the info structure.*/
/*Checks if node or var are null, which will result in being unsuccessful*/
/*In the while loop, iterations occur over each node*/
/*Starts with checks node's string starts with var*/
/*Returns pointer to position where the match is or NULL if no match.*/
/*If p is not NULL and the character it points to is '='*/
/*Node's string is excat match for environment variable. It then deletes node*/
/*x is then set to 0 and the loops runs until all nodes have been checked*/
}

/**
 * _setenv - Sets a new environment variable, or modify an existing one
 * @info: Structure containing potential arguments.
 * @var: The string env var property.
 * @value: The string env var value.
 *
 * Return: Always 0.
 */
int _setenv(info_t *info, char *var, char *value)
{
char *buf = NULL;
list_t *node;
char *p;

if (!var || !value)
return (0);

buf = malloc(_strlen(var) + _strlen(value) + 2);
if (!buf)
return (1);
_strcpy(buf, var);
_strcat(buf, "=");
_strcat(buf, value);
node = info->env;
while (node)
{
p = starts_with(node->str, var);
if (p && *p == '=')
{
free(node->str);
node->str = buf;
info->env_changed = 1;
return (0);
}
node = node->next;
}
add_node_end(&(info->env), buf, 0);
free(buf);
info->env_changed = 1;
return (0);
/*Basically searches for an existing node that matches specified variable*/
/*Updates the value, or adds a new node if no match is found.*/
}
