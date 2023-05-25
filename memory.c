#include "shell.h"

/**
 * bfree - frees pointer NULLs address
 * @jail: pointer free address
 *c language is used
 * Return: 1 if freed, otherwise 0.
 */
int bfree(void **jail)
{
	if (jail && *jail)
/*pointers and null addres to be freed*/
	{
		free(*jail);
/*pointer to free*/
		*jail = NULL;
/*null address to be freed*/
		return (1);
	}
	return (0);
}
/*log rolling is nailed*/
