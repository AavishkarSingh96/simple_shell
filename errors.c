#include "shell.h"

/**
 * prstr - input string
 * @line: the string
 *c is used here
 * Return: Nothing
 */
void prstr(char *line)
{
<<<<<<< HEAD
if (!str)
return;

while (*str)
{
_eputchar(*str);
str++;
}
/*The code above checks whether str is null and returns it if so.*/
/*If not null, it goes through each character of the string using a pointer*/
=======
	int aa = 0;
/*mix not up the two*/
	if (!line)
		return;
	while (line[aa] != '\0')
	{
		_camera(line[aa]);
		aa++;
	}
>>>>>>> d7febdd3e596410343bf9d607f99b57a080e46b7
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
<<<<<<< HEAD
static char buf[WRITE_BUF_SIZE] = "";
static int i;

if (c == BUF_FLUSH || i >= WRITE_BUF_SIZE - 1)
{
write(2, buf, i);
i = 0;
}
if (c != BUF_FLUSH)
buf[i++] = c;

return (1);
/*buf is a static character array declared with size of [WRITE_BUF_SIZE]*/
/*if c = BUF_FLUSH or i exceeds [WRITE_BUF_SIZE - 1],*/
/*buf elements will be errored*/
=======
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
>>>>>>> d7febdd3e596410343bf9d607f99b57a080e46b7
}
/*the last section*/
/**
<<<<<<< HEAD
 * _putfd - writes the character c to given fd
 * @c: The character to print
 * @fd: The file descriptor to write to
=======
 * tree - c to given fd
 * @pp: The character to print
 * @bam: The filedescriptor to write to
>>>>>>> d7febdd3e596410343bf9d607f99b57a080e46b7
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int tree(char pp, int bam)
{
<<<<<<< HEAD
static char buf[WRITE_BUF_SIZE] = "";
static int i;

if (c == BUF_FLUSH || i >= WRITE_BUF_SIZE - 1)
{
write(fd, buf, i);
i = 0;
}

if (c != BUF_FLUSH)
buf[i++] = c;

return (1);
/*if c = BUF_FLUSH and i exceeds [WRITE_BUF_SIZE - 1]*/
/*buf elements will be written to specified fd*/
}

/**
 * _putsfd - prints an input string
 * @str: the string to be printed
 * @fd: the file descriptor to write to
 *
=======
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
>>>>>>> d7febdd3e596410343bf9d607f99b57a080e46b7
 * Return: the number of chars put
 */
int xerox(char *bank, int green)
{
<<<<<<< HEAD
int count = 0;

if (!str)
return (0);

while (*str)
{
count += _putfd(*str++, fd);
}

return (count);
/*if str is null, 0 is returned*/
/*if not,function enters a loop going through each character using a pointer*/
/*after iterating through all the values,it returns the final value of count*/
=======
	int gg = 0;
/*this is necessary*/
	if (!bank)
		return (0);
	while (*bank)
	{
		gg += printgreen(*bank++, green);
	}
	return (gg);
>>>>>>> d7febdd3e596410343bf9d607f99b57a080e46b7
}
