#include "shell.h"

/**
 * _strlen - returns the length of a string
 * @sc: length check
 *this is c language
 * Return: integer length
 */
int _strlen(char *sc)
{
	int aa = 0;
/*the string whose length to check*/
	if (!sc)
		return (0);
/*integer length of string*/
	while (*sc++)
		aa++;
	return (aa);
}
/*context for code provided*/
/**
 * _strcmp - performs lexicogarphic.
 * @za1: the first string
 * @za2: the second string
 *performs lexicogarphic comparison of two strangs
 * Return: negative if s1 < s2, positive if s1 > s2, zero if s1 == s2
 */
int _strcmp(char *za1, char *za2)
/*to determine success or fail*/
{
	while (*za1 && *za2)
	{
		if (*za1 != *za2)
			return (*za1 - *za2);
		za1++;
		za2++;
	}
	if (*za1 == *za2)
		return (0);
	else
		return (*za1 < *za2 ? -1 : 1);
}
/*this is the end of section s1*/
/**
 * starts_with - checks if needle starts haystack
 * @hstr: string to search
 * @nstr: the substring to find
 *checks if needle starts haystack
 * Return: address of next char of haystack or NULL
 */
char *starts_with(const char *hstr, const char *nstr)
{
	while (*nstr)
		if (*nstr++ != *hstr++)
			return (NULL);
	return ((char *)hstr);
}
/*success is haystack address*/
/**
 * _strcat - concatenates two strings
 * @db: the destination buffer
 * @sob: the source buffer
 *two strings concats
 * Return: pointer to destination buffer
 */
char *_strcat(char *db, char *sob)
{
	char *gon = db;
/*input the dest buffer*/
	while (*db)
		db++;
/*input source buffer*/
	while (*sob)
		*db++ = *sob++;
/*source concacts dest buffer*/
	*db = *sob;
	return (gon);
}
/*failure to communicate*/
