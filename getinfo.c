#include "shell.h"

/**
 * wipe - initializes gps_t struct
 * @gps: struct address
 */
void wipe(gps_t *gps)
{
	gps->arg = NULL;
	gps->argv = NULL;
	gps->path = NULL;
	gps->argc = 0;
}
/*this is just context*/
/**
 * build - initializes info_t struct
 * @gps: struct address
 * @court: argument vector
 */
void build(gps_t *gps, char **court)
{
	int ac = 0;

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
		for (ac = 0; gps->argv && gps->argv[ac]; ac++)
			;
		gps->argc = ac;
/*this is still section two*/
		replace_alias(gps);
		replace_vars(gps);
	}
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
		_putchar(BUF_FLUSH);
	}
}
/* laser like concentration*/
