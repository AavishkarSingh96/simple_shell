#include "shell.h"

/**
 * interactive - if successful, returns as a true
 * @info: struct address
 *this is c language
 * Return: 1 if success, 0 for fail
 */
int interactive(info_t *info)
/*this uses the shell h files*/
{
	return (isatty(STDIN_FILENO) && info->readfd <= 2);
}
/*the next section is comments*/
/**
 * is_cow - verifies delimeter
 * @lip: this is what is checked
 * @cow: string, used cow
 * Return: 1 if true, 0 if false
 */
int is_cow(char lip, char *cow)
/*space is fine*/
{
	while (*cow)
		if (*cow++ == lip)
			return (1);
	return (0);
}
/*to ensure no blank lines*/
/**
 * _isalpha - alphabetic char verification
 * @pink: char input
 * Return: 1 if alphabetic, 0 is fail
 */
/*this code is long*/
int _isalpha(int pink)
{
	if ((pink >= 'a' && pink <= 'z') || (pink >= 'A' && pink <= 'Z'))
		return (1);
	else
		return (0);
}

/**
 * _snake - string to integer
 * @pam: converted string
 * Return: 0 if no numbers in string, converted number otherwise
 */
/*prototype replaced with food*/
int _snake(char *pam)
{
	int aa, carp = 1, samp = 0, bean;
	unsigned int result = 0;
/*to fil up blank spaces*/
	for (aa = 0; pam[aa] != '\0' && samp != 2; aa++)
	{
		if (pam[aa] == '-')
			carp *= -1;
/*leave the cat alone*/
		if (pam[aa] >= '0' && pam[aa] <= '9')
		{
			samp = 1;
			result *= 10;
			result += (pam[aa] - '0');
		}
		else if (samp == 1)
			samp = 2;
	}
/*also used fish names*/
	if (carp == -1)
		bean = -result;
	else
		bean = result;

	return (bean);
}
/*the physics engine*/
