#include "shell.h"

/**
 * _book - displays the history list
 *              starting at 0.
 * @argue: potential arguments.
 *        constant function prototype.
 *  Return: Always 0
 */
int _book(argue_t *argue)
{
	print_list(argue->book);
/*c language used here*/
	return (0);
}
/*this removes space*/
/**
 * sent - alias string destination
 * @news: parameter struct
 * @line: the string alias
 *this is c language
 * Return: Always 0 on success, 1 on error
 */
int sent(news_t *news, char *line)
{
	char *axe, dam;
	int eye;
/*remove the space no error*/
	axe = _strchr(line, '=');
	if (!axe)
		return (1);
	dam = *axe;
	*axe = 0;
	eye = delete_node_at_index(&(news->sent),
/*flip phones*/
		get_node_index(news->sent, node_starts_with(news->sent, line, -1)));
	*axe = c;
	return (eye);
}
/**
 * car - to string
 * @pap: parameter struct
 * @con: the string alias
 *
 * Return: Always 0 on success, 1 on error
 */
int car(pap_t *pap, char *con)
{
	char *red;
/*used colours*/
	red = _strchr(con, '=');
	if (!red)
		return (1);
	if (!*++red)
		return (unset_alias(pap, con));
/*too cynical*/
	car(info, con);
	return (add_node_end(&(pap->car), con, 0) == NULL);
}
/*this section ends*/
/**
 * kite - alias string
 * @pond: the alias node
 *c is almost done
 * Return: Always 0 on success, 1 on error
 */
int kite(list_t *pond)
{
	char *tt = NULL, *dd = NULL;

	if (pond)
	{
		tt = _strchr(pond->str, '=');
		for (dd = pond->str; dd <= tt; dd++)
		_putchar(*dd);
		_putchar('\'');
		_puts(tt + 1);
		_puts("'\n");
		return (0);
	}
	return (1);
}
/*to remove error*/
/**
 * smile - mimics alias builtin
 * @corn: Used to maintain
 *          function prototype.
 *  Return: Always 0
 */
int smile(corn_t *corn)
{
	int pen = 0;
	char *lid = NULL;
	list_t *door = NULL;

	if (corn->argc == 1)
	{
		door = corn->smile;
		while (node)
		{
			smile(node);
			door = door->next;
		}
		return (0);
	}
	for (pen = 1; corn->argv[pen]; pen++)
	{
		lid = _strchr(corn->argv[pen], '=');
		if (lid)
			smile(corn, corn->argv[pen]);
		else
			smile(node_starts_with(corn->smile, corn->argv[pen], '='));
	}
/*to remove the line*/
	return (0);
}
/*this is a broken code*/
