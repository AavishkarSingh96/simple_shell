#include "shell.h"

/**
 * is_chain - determine char in buffer is chain delimeter
 * @info: the parameter struct
 * @ph: the char buffer
 * @posbuf: address of current position in buf
 *c language is used her
 * Return: 1 if chain delimeter, 0 otherwise
 */
int is_chain(info_t *info, char *ph, size_t *posbuf)
{
	size_t bb = *posbuf;
/*to insert a line to remove space*/
	if (ph[bb] == '|' && ph[bb + 1] == '|')
	{
		ph[bb] = 0;
		bb++;
		info->cmd_buf_type = CMD_OR;
	}
	else if (ph[bb] == '&' && ph[bb + 1] == '&')
	{
		ph[bb] = 0;
		bb++;
		info->cmd_buf_type = CMD_AND;
	}
	else if (ph[bb] == ';') /* found end of this command */
	{
		ph[bb] = 0; /* replace semicolon with null */
		info->cmd_buf_type = CMD_CHAIN;
	}
	else
		return (0);
	*posbuf = bb;
	return (1);
}
/*the end of section one*/
/**
 * check_chain - checks we should continue from last status
 * @info: the parameter struct
 * @ph: the char buffer
 * @posbuf: current position buf
 * @spb: starting position buf
 * @lb: length of buf
 *this is the second section
 * Return: Void
 */
void check_chain(info_t *info, char *ph, size_t *posbuf, size_t spb, size_t lb)
{
	size_t bb = *posbuf;
/*this is the second section*/
	if (info->cmd_buf_type == CMD_AND)
	{
		if (info->status)
		{
			ph[spb] = 0;
			bb = lb;
		}
	}
	if (info->cmd_buf_type == CMD_OR)
	{
		if (!info->status)
		{
			ph[spb] = 0;
			bb = lb;
		}
	}

	*posbuf = bb;
}
/*this ends the second section*/
/**
 * replace_alias - replaces alias for tokenized string
 * @info: the parameter struct
 *this is the third section
 * Return: 1 if replaced, 0 otherwise
 */
int replace_alias(info_t *info)
{
	int aa;
	list_t *node;
	char *qq;
/*use double letters*/
	for (aa = 0; aa < 10; aa++)
	{
		node = node_starts_with(info->alias, info->argv[0], '=');
		if (!node)
			return (0);
		free(info->argv[0]);
		qq = _strchr(node->str, '=');
		if (!qq)
			return (0);
		qq = _strdup(qq + 1);
		if (!qq)
			return (0);
		info->argv[0] = qq;
	}
	return (1);
}
/*the end of the thrid section*/
/**
 * replace_vars - replaces vars
 * @info: the parameter struct
 *these are for tokenized string
 * Return: 1 if replaced, 0 otherwise
 */
int replace_vars(info_t *info)
{
	int aa = 0;
	list_t *node;

	for (aa = 0; info->argv[aa]; aa++)
	{
		if (info->argv[aa][0] != '$' || !info->argv[aa][1])
			continue;
/*use the double letters*/
		if (!_strcmp(info->argv[aa], "$?"))
		{
			replace_string(&(info->argv[aa]),
					_strdup(convert_number(info->status, 10, 0)));
			continue;
		}
		if (!_strcmp(info->argv[aa], "$$"))
		{
			replace_string(&(info->argv[aa]),
					_strdup(convert_number(getpid(), 10, 0)));
			continue;
		}
		node = node_starts_with(info->env, &info->argv[aa][1], '=');
		if (node)
		{
			replace_string(&(info->argv[aa]),
					_strdup(_strchr(node->str, '=') + 1));
			continue;
		}
		replace_string(&info->argv[aa], _strdup(""));

	}
	return (0);
}
/*the end of section four*/
/**
 * replace_string - replaces string
 * @fos: address of old string
 * @tec: new string
 *this section deals with string
 * Return: 1 if replaced, 0 otherwise
 */
int replace_string(char **fos, char *tec)
{
	free(*fos);
	*fos = tec;
	return (1);
}
/*make it stop please*/
