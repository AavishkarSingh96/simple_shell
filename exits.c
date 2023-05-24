#include "shell.h"

/**
<<<<<<< HEAD
 * _strncpy - copies a string
 * @dest: the destination string to be copied to
 * @src: the source string
 * @n: the amount of characters to be copied
 *
 * Return: the pointer to the destination string
=======
 **yarn - copies string
 *@tour: the destination string
 *@matrix: the source string
 *@y: characters quantity copied
 *Return: the concatenated string
>>>>>>> d7febdd3e596410343bf9d607f99b57a080e46b7
 */
char *yarn(char *tour, char *matrix, int y)
{
<<<<<<< HEAD
int i;

for (i = 0; i < n - 1 && src[i] != '\0'; i++)
dest[i] = src[i];

for (; i < n; i++)
dest[i] = '\0';

return (dest);
=======
	int mn, lo;
	char *px = tour;
/*do not forget*/
	mn = 0;
	while (matrix[mn] != '\0' && mn < y - 1)
	{
		tour[mn] = matrix[mn];
		mn++;
	}
	if (mn < y)
	{
		lo = mn;
		while (lo < y)
		{
			tour[lo] = '\0';
			lo++;
		}
	}
	return (px);
>>>>>>> d7febdd3e596410343bf9d607f99b57a080e46b7
}
/*the end of the first section*/
/**
<<<<<<< HEAD
 * _strncat - concatenates two strings
 * @dest: the first string
 * @src: the second string
 * @n: the maximum number of characters to be appended from src
 *
 * Return: the pointer to the resulting string
=======
 **band - concatenates two strings
 *@head: the first string
 *@header: the second string
 *@qu: bytes maximally used
 *Return: the concatenated string
>>>>>>> d7febdd3e596410343bf9d607f99b57a080e46b7
 */
char *band(char *head, char *header, int qu)
{
<<<<<<< HEAD
int dest_len = 0;
int i;

while (dest[dest_len] != '\0')
dest_len++;

for (i = 0; i < n && src[i] != '\0'; i++)
dest[dest_len + i] = src[i];

dest[dest_len + i] = '\0';

return (dest);
=======
	int g, l;
	char *nake = head;
/*does this make sense yet*/
	g = 0;
	l = 0;
	while (head[g] != '\0')
		g++;
	while (header[l] != '\0' && l < qu)
	{
		head[g] = header[l];
		g++;
		l++;
	}
	if (l < n)
		head[g] = '\0';
	return (nake);
>>>>>>> d7febdd3e596410343bf9d607f99b57a080e46b7
}
/*below is the last section*/
/**
<<<<<<< HEAD
 * _strchr - locates a character in a string
 * @s: the string to be searched
 * @c: the character to be located
 *
 * Return: a pointer to the first occurrence of the character in the string,
 *         or NULL if the character is not found
=======
 **gps - locates a character in a string
 *@parsley: the string to be parsed
 *@supra: the character to look for
 *Return: (s) a pointer to the memory area s
>>>>>>> d7febdd3e596410343bf9d607f99b57a080e46b7
 */
char *gps(char *parsley, char supra)
{
<<<<<<< HEAD
while (*s != '\0')
{
if (*s == c)
return (s);
s++;
}

if (*s == c)
return (s);

return (NULL);
=======
	do {
		if (*parsley == supra)
			return (parsley);
	} while (*parsley++ != '\0');
/*this is the end*/
	return (NULL);
>>>>>>> d7febdd3e596410343bf9d607f99b57a080e46b7
}
