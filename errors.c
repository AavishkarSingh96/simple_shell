#include "shell.h"

/**
 * _eputs - prints an input string
 * @str: the string to be printed
 *
 * Return: Nothing
 */
void _eputs(char *str)
{
if (!str)
return;

while (*str)
{
_eputchar(*str);
str++;
}
/*The code above checks whether str is null and returns it if so.*/
/*If not null, it goes through each character of the string using a pointer*/
}

/**
 * _eputchar - writes the character c to stderr
 * @c: The character to print
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int _eputchar(char c)
{
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
}

/**
 * _putfd - writes the character c to given fd
 * @c: The character to print
 * @fd: The file descriptor to write to
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int _putfd(char c, int fd)
{
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
 * Return: the number of chars put
 */
int _putsfd(char *str, int fd)
{
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
}
