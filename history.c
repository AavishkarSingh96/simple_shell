#include "shell.h"

/**
 * get_history_file - gets the history file
 * @info: parameter struct
 *c language is used here
 * Return: allocated string containg history file
 */
/*this section starts here*/
char *get_history_file(info_t *info)
/*Pinter for file history*/
{
	char *buf, *dir;

	dir = _getenv(info, "HOME=");
	if (!dir)
		return (NULL);
/*code will return when completed*/
	buf = malloc(sizeof(char) * (_strlen(dir) + _strlen(HIST_FILE) + 2));
	if (!buf)
		return (NULL);
/*Null returns to zero*/
	buf[0] = 0;
	_strcpy(buf, dir);
	_strcat(buf, "/");
	_strcat(buf, HIST_FILE);
	return (buf);
}
/*this section ends here*/
/**
 * write_history - creates a file.
 * @info: the parameter struct
 *or appends to an existing file
 * Return: 1 on success, else -1
 */
int write_history(info_t *info)
/*next section begins here*/
{
	ssize_t fd;
	char *filename = get_history_file(info);
	list_t *node = NULL;
/*filename is specified*/
	if (!filename)
		return (-1);
/*code will then return*/
	fd = open(filename, O_CREAT | O_TRUNC | O_RDWR, 0644);
	free(filename);
	if (fd == -1)
		return (-1);
/*code creates file from history*/
	for (node = info->history; node; node = node->next)
	{
		_putsfd(node->str, fd);
		_putfd('\n', fd);
	}
	_putfd(BUF_FLUSH, fd);
	close(fd);
	return (1);
}
/*this section ends here*/
/**
 * read_history - reads history from file
 * @info: the parameter struct
 *c language is used here
 * Return: histcount on success, 0 otherwise
 */
int read_history(info_t *info)
/*files to be read are selected*/
{
	int aa, last = 0, linecount = 0;
	ssize_t fd, rdlen, fsize = 0;
	struct stat st;
	char *buf = NULL, *filename = get_history_file(info);

	if (!filename) /*file history retrieved*/
		return (0);
	fd = open(filename, O_RDONLY);/*file name derived*/
	free(filename);
	if (fd == -1)
		return (0);
	if (!fstat(fd, &st))/*code will return as expected*/
		fsize = st.st_size;
	if (fsize < 2)
		return (0);
	buf = malloc(sizeof(char) * (fsize + 1));/*code returns as desired*/
	if (!buf)
		return (0);
	rdlen = read(fd, buf, fsize);/*buffer is derived*/
	buf[fsize] = 0;
	if (rdlen <= 0)
		return (free(buf), 0);
	close(fd);/*upon completion, this will revert*/
	for (aa = 0; aa < fsize; aa++)
		if (buf[aa] == '\n')
		{
			buf[aa] = 0;
			build_history_list(info, buf + last, linecount++);
			last = aa + 1;
		}
	if (last != aa)/*move to final part of this*/
		build_history_list(info, buf + last, linecount++);
	free(buf);
	info->histcount = linecount;
	while (info->histcount-- >= HIST_MAX)
		delete_node_at_index(&(info->history), 0);
	renumber_history(info);
	return (info->histcount);
}
/*this section ends*/
/**
 * build_history_list - adds entry to a history linked list
 * @info: Structure containing potential arguments. Used to maintain
 * @buf: buffer
 * @linecount: the history linecount, histcount
 *
 * Return: Always 0
 */
int build_history_list(info_t *info, char *buf, int linecount)
{
	list_t *node = NULL;

	if (info->history)
		node = info->history;
	add_node_end(&node, buf, linecount);

	if (!info->history)
		info->history = node;
	return (0);
}

/**
 * renumber_history - to linked list after changes
 * @info: Structure containing potential arguments. Used to maintain
 *c language used here
 * Return: the new histcount
 */
int renumber_history(info_t *info)
/*new final section starts here*/
{
	list_t *node = info->history;
	int aa = 0;
/*variable assigned value*/
	while (node)
	{
		node->num = aa++;
		node = node->next;
	}
	return (info->histcount = aa);
/*code returns upon completion*/
}
/*so human looking*/
