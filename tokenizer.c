#include "shell.h"

/**
 * **strtow - splits a string into words.
 * @ins: the input string
 * @ds: the delimeter string
 * Return: a pointer to an array of strings, or NULL on failure
 */
/*Repeat delimiters are ignored*/
char **strtow(char *ins, char *ds)
{
	int aa, bb, cc, dd, numwords = 0;
	char **ee;

	if (ins == NULL || ins[0] == 0)
		return (NULL);
	if (!ds)
		ds = " ";
	for (aa = 0; ins[aa] != '\0'; aa++)
		if (!is_delim(ins[aa], ds) && (is_delim(ins[aa + 1], ds) || !ins[aa + 1]))
			numwords++;
/*this code beward length*/
	if (numwords == 0)
		return (NULL);
	ee = malloc((1 + numwords) * sizeof(char *));
	if (!ee)
		return (NULL);
	for (aa = 0, bb = 0; bb < numwords; bb++)
	{
		while (is_delim(ins[aa], ds))
			aa++;
		cc = 0;
		while (!is_delim(ins[aa + cc], ds) && ins[aa + cc])
			cc++;
		ee[bb] = malloc((cc + 1) * sizeof(char));
		if (!ee[bb])
		{
			for (cc = 0; cc < bb; cc++)
				free(ee[cc]);
			free(ee);
			return (NULL);
		}
		for (dd = 0; dd < cc; dd++)
			ee[bb][dd] = ins[aa++];
		ee[bb][dd] = 0;
	}
	ee[bb] = NULL;
	return (ee);
}
/*thus ends the previous*/
/**
 * **strtow2 - splits a string into words
 * @ins: the input string
 * @ds: the delimeter
 * Return: on success, or NULL on failure
 */
char **strtow2(char *ins, char ds)
{
	int a, b, c, d, numwords = 0;
	char **e;
/*to view the string and delimeter*/
	if (ins == NULL || ins[0] == 0)
		return (NULL);
	for (a = 0; ins[a] != '\0'; a++)
		if ((ins[a] != ds && ins[a + 1] == ds) ||
				    (ins[a] != ds && !ins[a + 1]) || ins[a + 1] == ds)
			numwords++;
	if (numwords == 0)
		return (NULL);
	e = malloc((1 + numwords) * sizeof(char *));
	if (!e)
		return (NULL);
	for (a = 0, b = 0; b < numwords; b++)
		/*return on success*/
	{
		while (ins[a] == ds && ins[a] != ds)
			a++;
		c = 0;
		while (ins[a + c] != ds && ins[a + c] && ins[a + c] != ds)
			c++;
		e[b] = malloc((b + 1) * sizeof(char));
		if (!e[b])
		{
			for (c = 0; c < b; b++)
				free(e[c]);
			free(e);
			return (NULL);
		}
		/*next is for*/
		for (d = 0; d < c; d++)
			e[b][d] = ins[a++];
		e[b][d] = 0;
	}
	/*return on success*/
	e[b] = NULL;
	return (e);
}
/*welcome to the herd*/
