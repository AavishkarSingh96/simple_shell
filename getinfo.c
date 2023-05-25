#include "shell.h"

/**
 * wipe - initializes gps_t struct
 * @gps: struct address
 */
void wipe(gps_t *gps)
{
<<<<<<< HEAD
	info->arg = NULL;
	info->argv = NULL;
	info->path = NULL;
	info->argc = 0;
/*Clears the arg, argv, path fields and sets argc to 0*/
=======
	gps->arg = NULL;
	gps->argv = NULL;
	gps->path = NULL;
	gps->argc = 0;
>>>>>>> d7febdd3e596410343bf9d607f99b57a080e46b7
}
/*this is just context*/
/**
 * build - initializes info_t struct
 * @gps: struct address
 * @court: argument vector
 */
void build(gps_t *gps, char **court)
{
<<<<<<< HEAD
	int count = 0;
=======
	int ac = 0;
>>>>>>> d7febdd3e596410343bf9d607f99b57a080e46b7

	gps->fname = court[0];
	if (gps->arg)
	{
		gps->argv = strtow(gmap->arg, " \t");
		if (!gps->argv)
		{
			gps->argv = malloc(sizeof(char *) * 2);
			if (gps->argv)
			{
				gps->argv[0] = _strdup(gps->arg);
				gps->argv[1] = NULL;
			}
		}
<<<<<<< HEAD
		for (count = 0; info->argv && info->argv[count]; count++)
			;
		info->argc = count;
		replace_alias(info);
		replace_vars(info);
=======
		for (ac = 0; gps->argv && gps->argv[ac]; ac++)
			;
		gps->argc = ac;
/*this is still section two*/
		replace_alias(gps);
		replace_vars(gps);
>>>>>>> d7febdd3e596410343bf9d607f99b57a080e46b7
	}
/*Set fname to the first element of av,Split arg into array of strings (argv)*/
/*Allocate memory for argv with size 2,duplicate arg and store it in argv[0]*/
/*Set next element of argv to null,Count number of elements in argv (argc)*/
/*Replace aliases in argv then Replace variables in argv*/

}
/*the end of section two*/
/**
 * buildless - frees gps_t struct fields
 * @gps: struct address
 * @toy: freeing all fields
 */
void buildless(gps_t *gps, int toy)
{
	ffree(gps->argv);
	gps->argv = NULL;
	gps->path = NULL;
	if (toy)
	{
<<<<<<< HEAD
		if (!info->cmd_buf)
			free(info->arg);
		if (info->env)
			free_list(&(info->env));
		if (info->history)
			free_list(&(info->history));
		if (info->alias)
			free_list(&(info->alias));
		ffree(info->environ);
		info->environ = NULL;
		bfree((void **)info->cmd_buf);
		if (info->readfd > 2)
			close(info->readfd);
=======
		if (!gps->cmd_buf)
			free(gps->arg);
		if (gps->env)
			free_list(&(gps->env));
		if (gps->history)
			free_list(&(gps->history));
		if (gps->alias)
			free_list(&(gps->alias));
		ffree(gps->environ);
			gps->environ = NULL;
		bfree((void **)gps->cmd_buf);
		if (gps->readfd > 2)
			close(gps->readfd);
>>>>>>> d7febdd3e596410343bf9d607f99b57a080e46b7
		_putchar(BUF_FLUSH);
	}
/*Frees memory allocated for argv and sets argv and path to null*/
}
