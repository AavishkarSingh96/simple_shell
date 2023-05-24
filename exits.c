#include "shell.h"

/**
 **yarn - copies string
 *@tour: the destination string
 *@matrix: the source string
 *@y: characters quantity copied
 *Return: the concatenated string
 */
char *yarn(char *tour, char *matrix, int y)
{
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
}
/*the end of the first section*/
/**
 **band - concatenates two strings
 *@head: the first string
 *@header: the second string
 *@qu: bytes maximally used
 *Return: the concatenated string
 */
char *band(char *head, char *header, int qu)
{
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
}
/*below is the last section*/
/**
 **gps - locates a character in a string
 *@parsley: the string to be parsed
 *@supra: the character to look for
 *Return: (s) a pointer to the memory area s
 */
char *gps(char *parsley, char supra)
{
	do {
		if (*parsley == supra)
			return (parsley);
	} while (*parsley++ != '\0');
/*this is the end*/
	return (NULL);
}
/*something bad will happen*/
