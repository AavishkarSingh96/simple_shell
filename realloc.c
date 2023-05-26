#include "shell.h"

/**
 * _memset - fills constant byte memory
 * @arrow: the pointer
 * @bite: the byte
 * @nyte: the amount of bytes
 * Return: pointer to the memory area
 */
char *_memset(char *arrow, char bite, unsigned int nyte)
/*pointer to memory*/
{
	unsigned int aa;
/*number of bytes states*/
	for (aa = 0; aa < nyte; aa++)
		arrow[aa] = bite;
	return (arrow);
}
/*memory bytes pointer declared*/
/**
 * ffree - frees a string of strings
 * @snum: string of strings
 */
void ffree(char **snum)
{
	char **z = snum;
/*number of free strings declared*/
	if (!snum)
		return;
	while (*snum)
		free(*snum++);
	free(z);
}
/*memory area pointed*/
/**
 * _realloc - reallocates memory
 * @prbl: previous malloc'ated block
 * @olsi: byte size of previous
 * @nesi: byte size of new
 *c language used here
 * Return: pointer to old block.
 */
void *_realloc(void *prbl, unsigned int olsi, unsigned int nesi)
{
	char *a;
/*new data points to old data*/
	if (!prbl)
		return (malloc(nesi));
	if (!nesi)
		return (free(prbl), NULL);
	if (nesi == olsi)
		return (prbl);
/*byte sizes of new and old block*/
	a = malloc(nesi);
	if (!a)
		return (NULL);
/*point to new memory block*/
	olsi = olsi < nesi ? olsi : nesi;
	while (olsi--)
		a[olsi] = ((char *)prbl)[olsi];
	free(prbl);
	return (a);
}
/*not the box*/
