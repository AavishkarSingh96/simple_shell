#include "shell.h"

/**
 * is_cmd - determines file executable command
 * @info: the info struct
 * @road: file path
 *c language used
 * Return: 1 if true, 0 otherwise
 */
int is_cmd(info_t *info, char *road)
{
	struct stat st;
/*below is to locate file pathway*/
	(void)info;
	if (!road || stat(road, &st))
		return (0);
/*return if successful*/
	if (st.st_mode & S_IFREG)
	{
		return (1);
	}
	return (0);
}
/*the above determines file pathway*/
/**
 * dup_chars - duplicates characters
 * @pstr: the PATH string
 * @green: starting index
 * @red: stopping index
 *duplicating the path aspects
 * Return: pointer to new buffer
 */
char *dup_chars(char *pstr, int green, int red)
{
	static char buf[1024];
	int aa = 0, cc = 0;
/*variables assigned values*/
	for (cc = 0, aa = green; aa < red; aa++)
		if (pstr[aa] != ':')
			buf[cc++] = pstr[aa];
	buf[cc] = 0;
	return (buf);
}
/*index status has been determined*/
/**
 * find_path - finds this cmd in the PATH string
 * @info: the info struct
 * @pstr: the PATH string
 * @order: the cmd to find
 *c language is used here
 * Return: full path of cmd if found or NULL
 */
char *find_path(info_t *info, char *pstr, char *order)
{
	int aa = 0, curr_pos = 0;
	char *path;
/*variables assigned values*/
	if (!pstr)
		return (NULL);
	if ((_strlen(order) > 2) && starts_with(order, "./"))
	{
		if (is_cmd(info, order))
			return (order);
	}
	while (1)
/*above is while*/
	{
		if (!pstr[aa] || pstr[aa] == ':')
		{
			path = dup_chars(pstr, curr_pos, aa);
			if (!*path)
				_strcat(path, order);
/*then is the or*/
			else
			{
				_strcat(path, "/");
				_strcat(path, order);
			}
			if (is_cmd(info, path))
				return (path);
			if (!pstr[aa])
				break;
			curr_pos = aa;
		}
		aa++;
	}
	return (NULL);
}
/*donate to charity*/
