#include "shell.h"

/**
 * add_node - start of the list
 * @head: address of pointer
 * @str: field of node
 * @num: used by history
 *c language is used
 * Return: size of list
 */
list_t *add_node(list_t **head, const char *str, int num)
/*new head lis listed below*/
{
	list_t *new_head;
/*return if NULL result is recieved*/
	if (!head)
		return (NULL);
	new_head = malloc(sizeof(list_t));
/*next is the if section*/
	if (!new_head)
		return (NULL);
	_memset((void *)new_head, 0, sizeof(list_t));
	new_head->num = num;
/*return if there is a fail*/
	if (str)
	{
		new_head->str = _strdup(str);
		if (!new_head->str)
		{
			free(new_head);
			return (NULL);
		}
	}
	new_head->next = *head;
	*head = new_head;
	return (new_head);
}
/*new head if thus obtained*/
/**
 * add_node_end - end of the list
 * @head: address of pointer
 * @str: field of node
 * @num: used by history
 *c language used again
 * Return: list
 */
list_t *add_node_end(list_t **head, const char *str, int num)
/*node index referenced*/
{
	list_t *new_node, *node;
/*new node listed in the section*/
	if (!head)
		return (NULL);
/*address of head listed within section*/
	node = *head;
	new_node = malloc(sizeof(list_t));
	if (!new_node)
		return (NULL);
/*Null returned if fail*/
	_memset((void *)new_node, 0, sizeof(list_t));
	new_node->num = num;
	if (str)
	{
		new_node->str = _strdup(str);
		if (!new_node->str)
		{
			free(new_node);
			return (NULL);
		}
	}
/*next sections moves to if*/
	if (node)
	{
		while (node->next)
			node = node->next;
		node->next = new_node;
	}
/*After this proceed to return*/
	else
		*head = new_node;
	return (new_node);
}
/*thus ends the third section*/
/**
 * print_list_str - list_t linked list
 * @tt: first node
 *prints only the str element of a list_t linked list
 * Return: size of list
 */
size_t print_list_str(const list_t *tt)
{
	size_t aa = 0;
/*variable value assigned*/
	while (tt)
	{
		_puts(tt->str ? tt->str : "(nil)");
		_puts("\n");
		tt = tt->next;
		aa++;
	}
	return (aa);
}
/*linked list is printed in above section*/
/**
 * delete_node_at_index -as specified
 * @head: address first node
 * @index: to delete
 *head and index focused on
 * Return: 1 on success, 0 on failure
 */
/*this breaks the sections*/
/**
 * delete_node_at_index - selected nodes are deleted
 * @head: first node address
 * @index: node to delete
 *deletes node at given index
 * Return: 1 on success, 0 on failure
 */
int delete_node_at_index(list_t **head, unsigned int index)
/*variables assisgned values*/
{
	list_t *node, *prev_node;
/*integre assigned value*/
	unsigned int aa = 0;
/*first node address specified*/
	if (!head || !*head)
		return (0);
/*first node designated*/
	if (!index)
	{
		node = *head;
		*head = (*head)->next;
		free(node->str);
		free(node);
		return (1);
	}
	node = *head;
	while (node)
/*head and tail node assigned*/
	{
		if (aa == index)
		{
			prev_node->next = node->next;
			free(node->str);
			free(node);
			return (1);
		}
/*node index to deleted specified*/
		aa++;
		prev_node = node;
		node = node->next;
	}
	return (0);
}
/*this concludes the section*/
/**
 * free_list - all nodes
 * @head_ptr: address of pointer to head node
 *c langauge used again
 * Return: void
 */
void free_list(list_t **head_ptr)
/*head node address specified*/
{
	list_t *node, *next_node, *head;
/*All nodes to be freed are listed*/
	if (!head_ptr || !*head_ptr)
		return;
	head = *head_ptr;
	node = head;
	while (node)
/*Code will rturn via Void*/
	{
		next_node = node->next;
		free(node->str);
		free(node);
		node = next_node;
	}
	*head_ptr = NULL;
}
/*this concludes this section*/
