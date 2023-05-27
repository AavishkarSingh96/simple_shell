#include "shell.h"

/**
 * **strtow - splits a string into words.
 * @str: the input string
 * @d: the delimeter string
 * Return: success is array of strings, or NULL on failure
 */
/*this begins here*/
char **strtow(char *str, char *d)
{
	int a, b, c, e, numwords = 0;
	char **f;
/*Repeat delimiters removed*/
	if (str == NULL || str[0] == 0)
		return (NULL);
	if (!d)
		d = " ";
	for (a = 0; str[a] != '\0'; a++)
		if (!(str[a] d) && ((str[a + 1] d) || !str[a + 1]))
			numwords++;
/*string array returned on success*/
	if (numwords == 0)
		return (NULL);
	f = malloc((1 + numwords) * sizeof(char *));
	if (!f)
		return (NULL);
	for (a = 0, b = 0; b < numwords; b++)
	{
		while ((str[a] d))
			a++;
		c = 0;
		while (!(str[a + c] d) && str[a + c])
			c++;
		f[b] = malloc((c + 1) * sizeof(char));
		if (!f[b])
		{
			for (c = 0; c < b; c++)
				free(f[c]);
			free(s);
			return (NULL);
		}
		for (e = 0; e < c; e++)
			f[b][e] = str[a++];
		f[b][e] = 0;
	}
	f[b] = NULL;
	return (f);
}
/*this concludes part one*/
/**
 * **strtow2 - splits a string into words
 * @str: the input string
 * @d: the delimeter
 * Return: success is array of strings, or NULL on failure
 */
char **strtow2(char *str, char d)
{
	int a, b, c, e, numwords = 0;
	char **f;
/*string is split into words*/
	if (str == NULL || str[0] == 0)
		return (NULL);
	for (a = 0; str[a] != '\0'; a++)
		if ((str[a] != d && str[a + 1] == d) ||
				    (str[a] != d && !str[a + 1]) || str[a + 1] == d)
			numwords++;
	if (numwords == 0)
		return (NULL);
	f = malloc((1 + numwords) * sizeof(char *));
	if (!f)
		return (NULL);
/*Null is returned if fail*/
	for (a = 0, b = 0; b < numwords; b++)
	{
		while (str[a] == d && str[a] != d)
			a++;
		c = 0;
		while (str[a + c] != d && str[a + c] && str[a + c] != d)
			c++;
		f[b] = malloc((c + 1) * sizeof(char));
		if (!f[b])
		{
			for (c = 0; c < b; c++)
				free(f[c]);
			free(f);
			return (NULL);
/*variables assigned values*/
		}
		for (e = 0; e < c; e++)
			f[b][e] = str[a++];
		f[b][e] = 0;
	}
	f[b] = NULL;
	return (f);
}
/*this is the conclusion*/
