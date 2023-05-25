#include "shell.h"

/**
 * _strcpy - copies a string
 * @loc: the destination
 * @pnt: the source
 *string copied from one to other
 * Return: pointer to destination
 */
char *_strcpy(char *loc, char *pnt)
{
	int aa = 0;
/*int assigned value*/
	if (loc == pnt || pnt == 0)
		return (loc);
	while (pnt[aa])
	{
		loc[aa] = pnt[aa];
		aa++;
	}
	loc[aa] = 0;
	return (loc);
}
/*int value assigned*/
/**
 * _strdup - duplicates a string
 * @sdup: the string to duplicate
 *string duplicated in the section
 * Return: pointer to the duplicated string
 */
char *_strdup(const char *sdup)
{
	int l = 0;
	char *gon;

	if (sdup == NULL)
		return (NULL);
	while (*sdup++)
		l++;
	gon = malloc(sizeof(char) * (l + 1));
	if (!gon)
		return (NULL);
	for (l++; l--;)
		gon[l] = *--sdup;
	return (gon);
}
/*string is duplicated*/
/**
 * _puts - prints an input string
 * @spri: the string to be printed
 *input string then printed
 * Return: Nothing
 */
void _puts(char *spri)
{
	int aa = 0;
/*string to print*/
	if (!spri)
		return;
	while (spri[aa] != '\0')
	{
		_putchar(spri[aa]);
		aa++;
	}
}
/*henc string is printed*/
/**
 * _putchar - c to stdout
 * @prac: The character to print
 *writes the character c to stdout
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int _putchar(char prac)
{
	static int aa;
	static char buf[WRITE_BUF_SIZE];
/*c shall stdout*/
	if (prac == BUF_FLUSH || aa >= WRITE_BUF_SIZE)
	{
		write(1, buf, aa);
		aa = 0;
	}
	if (prac != BUF_FLUSH)
		buf[aa++] = prac;
	return (1);
}
/*the danish chick*/
