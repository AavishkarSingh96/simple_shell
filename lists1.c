#include "shell.h"

/**
 * list_len - length linked list
 * @dd: pointer to first node
 *c language is used
 * Return: size of list
 */
size_t list_len(const list_t *dd)
/*variables assigned values*/
{
	size_t aa = 0;
/*first node pointed to*/
	while (dd)
	{
		dd = dd->next;
		aa++;
	}
/*Code will then return*/
	return (aa);
}
/*first section is concluded*/
/**
 * list_to_strings - returns array of strings list->str
 * @head: pointer to first node
 *c language is used
 * Return: array of strings
 */
char **list_to_strings(list_t *head)
/*node head is indicated*/
{
	list_t *node = head;
/*variables assigned value*/
	size_t aa = list_len(head), bb;
	char **strs;
	char *str;
/*string is located*/
	if (!head || !aa)
		return (NULL);
	strs = malloc(sizeof(char *) * (aa + 1));
	if (!strs)
		return (NULL);
	for (aa = 0; node; node = node->next, aa++)
	{
		str = malloc(_strlen(node->str) + 1);
		if (!str)
/*section break inserted*/
		{
			for (bb = 0; bb < aa; bb++)
				free(strs[bb]);
			free(strs);
			return (NULL);
		}
/*nodes freed and code returns*/
		str = _strcpy(str, node->str);
		strs[aa] = str;
	}
	strs[aa] = NULL;
	return (strs);
}
/*thus ends this section*/
/*next section begins*/
/**
 * print_list - a list_t linked list
 * @tt: pointer to first node
 *prints all elements
 * Return: size of list
 */
size_t print_list(const list_t *tt)
{
	size_t aa = 0;
/*pointer indicates first node*/
	while (tt)
	{
		_puts(convert_number(tt->num, 10, 0));
		_putchar(':');
		_putchar(' ');
		_puts(tt->str ? tt->str : "(nil)");
		_puts("\n");
		tt = tt->next;
		aa++;
	}
	return (aa);
}
/*this section ends*/
/**
 * node_starts_with - string starts with prefix
 * @node: pointer to list head
 * @prefix: string to match
 * @io: after prefix to match
 *returns node
 * Return: match node or null
 */
list_t *node_starts_with(list_t *node, char *prefix, char io)
{
	char *qq = NULL;
/*variable assigned*/
	while (node)
	{
		qq = starts_with(node->str, prefix);
		if (qq && ((io == -1) || (*qq == io)))
			return (node);
		node = node->next;
	}
/*code returns*/
	return (NULL);
}
/*this section ends*/
/**
 * get_node_index - index of a node
 * @head: pointer to list head
 * @node: pointer to the node
 *gets the index
 * Return: index of node or -1
 */
ssize_t get_node_index(list_t *head, list_t *node)
/*first and last node searched*/
{
	size_t aa = 0;
/*values are assigned*/
	while (head)
/*rules are set*/
	{
		if (head == node)
			return (aa);
		head = head->next;
		aa++;
	}
	return (-1);
}
/*put down roots with*/
