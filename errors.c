#include "shell.h"

/**
 * _eputs - prints a string to stderr
 * @str: The string to be printed
 *
 * Return: Nothing
 */
void _eputs(char *str)
{
	int i = 0;

	if (!str)
		return;

	while (str[i] != '\0')
	{
		_eputchar(str[i]); /* Call _eputchar to print each character */
		i++;
	}
}

/**
 * _eputchar - writes a character to stderr
 * @c: The character
 *
 * Return: On success 1.
 *         On error, -1 is returned
 */
int _eputchar(char c)
{
	static int i;
	static char buf[WRITE_BUF_SIZE];

	if (c == BUF_FLUSH || i >= WRITE_BUF_SIZE)
	{
		write(2, buf, i); /* Write the buffer to stderr */
		i = 0;
	}
	if (c != BUF_FLUSH)
		buf[i++] = c;
	return (1);
}

/**
 * _putfd - writes a character
 * @c: The character
 * @fd: The file descriptor
 *
 * Return: On success 1.
 *         On error, -1 is returned
 */
int _putfd(char c, int fd)
{
	static int phy;
	static char buf[WRITE_BUF_SIZE];

	if (c == BUF_FLUSH || phy >= WRITE_BUF_SIZE)
	{
		write(fd, buf, phy); /* Write the buffer to the specified file descriptor */
		phy = 0;
	}
	if (c != BUF_FLUSH)
		buf[phy++] = c;
	return (1);
}

/**
 * _putsfd - prints a string
 * @str: The string
 * @fd: The file descriptor
 *
 * Return: The number of characters written
 */
int _putsfd(char *str, int fd)
{
	int x = 0;

	if (!str)
		return (0);

	while (*str)
	{
		x += _putfd(*str++, fd); /* Call _putfd to print each character */
	}
	return (x);
}
