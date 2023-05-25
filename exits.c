#include "shell.h"

/**
 * _strncpy - copies a string
 * @dest: The destination for the string
 * @src: The source string
 * @n: The number of characters copied
 *
 * Return: A pointer to the destination string
 */
char *_strncpy(char *dest, char *src, int n)
{
	int i, j;
	char *s = dest;

	i = 0;
	while (src[i] != '\0' && i < n - 1)
	{
		dest[i] = src[i];
		i++;
	}
	if (i < n)
	{
		j = i;
		while (j < n)
		{
			dest[j] = '\0';
		/* Add null characters to pad the remaining space */
			j++;
		}
	}
	return (s);
}

/**
 * _strncat - concatenates two strings
 * @dest: first string
 * @src: second string
 * @n: The maximum number of bytes to be used
 *
 * Return: A pointer to the concatenated string
 */
char *_strncat(char *dest, char *src, int n)
{
	int i, j;
	char *s = dest;

	i = 0;
	j = 0;
	while (dest[i] != '\0')
		i++;

	while (src[j] != '\0' && j < n)
	{
		dest[i] = src[j];
		i++;
		j++;
	}
	if (j < n)
		dest[i] = '\0';
	/* Add null character to terminate the concatenated string */
	return (s);
}

/**
 * _strchr - locates a character
 * @s: The string
 * @c: The character
 *
 * Return: A pointer to the first character in the string
 */
char *_strchr(char *s, char c)
{
	do {
		if (*s == c)
			return (s);
	} while (*s++ != '\0');

	return (NULL); /* Return NULL if the character is not found */
}
