#include "shell.h"

/**
 * clear_info - Initializes the fields of the info_t struct
 * @info: Pointer to the info_t struct
 */
void clear_info(info_t *info)
{
/* Set all fields to initial values or NULL */
info->arg = NULL;
info->argv = NULL;
info->path = NULL;
info->argc = 0;
}

/**
 * set_info - Sets the fields of the info_t structure
 * @info: Pointer to the info_t
 * @av: Argument vector
 */
void set_info(info_t *info, char **av)
{
int i = 0;

info->fname = av[0];

/* Check if the argument is provided */
if (info->arg)
{
/* Tokenize the argument string */
info->argv = strtow(info->arg, " \t");
if (!info->argv)
{
/* Handle memory allocation failure */
info->argv = malloc(sizeof(char *));
if (info->argv)
{
info->argv[0] = _strdup(info->arg);
info->argv[1] = NULL;
}
}

/* Count the number of arguments */
for (i = 0; info->argv && info->argv[i]; i++)
;
info->argc = i;

/* Replace aliases and variables in the arguments */
replace_alias(info);
replace_vars(info);
}
}

/**
 * free_info - Frees the dynamically allocated fields
 * @info: Pointer to the info_t
 * @all: True if freeing all fields
 */
void free_info(info_t *info, int all)
{
ffree(info->argv);
info->argv = NULL;
info->path = NULL;

if (all)
{
if (!info->cmd_buf)
free(info->arg);
/*Free dynamically allocated 'info->arg' if 'info->cmd_buf' is not allocated*/

if (info->env)
free_list(&(info->env));
/*Free the linked list in 'info->env' using 'free_list' function*/

if (info->history)
free_list(&(info->history));
/*Free the linked list in 'info->history' using 'free_list' function*/

if (info->alias)
free_list(&(info->alias));
/*Free the linked list in 'info->alias' using 'free_list' function*/

ffree(info->environ);
/*Deallocate the memory used by 'info->environ' using 'ffree' function*/

info->environ = NULL;
/*Set 'info->environ' to NULL after freeing the memory*/

bfree((void **)info->cmd_buf);

if (info->readfd > 2)
close(info->readfd);
/*Close the file descriptor if 'info->readfd' is greater than 2*/

_putchar(BUF_FLUSH);
}
}
