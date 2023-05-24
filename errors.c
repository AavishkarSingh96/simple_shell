#include "shell.h"

/**
 * prstr - input string
 * @line: the string
 *c is used here
 * Return: Nothing
 */
void prstr(char *line)
{
	int aa = 0;
/*mix not up the two*/
	if (!line)
		return;
	while (line[aa] != '\0')
	{
		_camera(line[aa]);
		aa++;
	}
}
/*why is that below*/
/**
 * camera - writes c to stderr
 * @pp: character print
 *scroll down
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int camera(char pp)
{
	static int bb;
	static char buf[WRITE_BUF_SIZE];
/*does this make sense*/
	if (pp == BUF_FLUSH || bb >= WRITE_BUF_SIZE)
	{
		write(2, buf, bb);
		bb = 0;
	}
	if (pp != BUF_FLUSH)
		buf[bb++] = pp;
	return (1);
}
/*the last section*/
/**
 * tree - c to given fd
 * @pp: The character to print
 * @bam: The filedescriptor to write to
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int tree(char pp, int bam)
{
	static int ff;
	static char pen[WRITE_BUF_SIZE];

	if (pp == BUF_FLUSH || ff >= WRITE_BUF_SIZE)
	{
		write(bam, pen, ff);
		ff = 0;
	}
	if (pp != BUF_FLUSH)
		pen[ff++] = pp;
	return (1);
}

/**
 * xerox - input string
 * @bank: string printed
 * @green: the filedescriptor
 *this is the last section
 * Return: the number of chars put
 */
int xerox(char *bank, int green)
{
	int gg = 0;
/*this is necessary*/
	if (!bank)
		return (0);
	while (*bank)
	{
		gg += printgreen(*bank++, green);
	}
	return (gg);
}
/*imagine they pull this*/
