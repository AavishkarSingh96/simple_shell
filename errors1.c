#include "shell.h"

/**
 * _erratoi - string to int conversion
 * @s: string
 * Return: 0 no numbers in string, converted number else
 * -1 on error
 */
int _erratoi(char *s)
{
	int i = 0;
	unsigned long int result = 0;

	if (*s == '+')
		s++; /* Skip leading + if present */
	for (i = 0;  s[i] != '\0'; i++)
	{
		if (s[i] >= '0' && s[i] <= '9') /*Check if character is digit*/
		{
			result *= 10;
			result += (s[i] - '0'); /*Convert character to number*/
			if (result > INT_MAX)
				return (-1); /*Return -1, num exceeds INT_MAX*/
		}
		else
			return (-1); /* Return -1 if non-digit character found */
	}
	return (result); /* Return the converted number */
}

/**
 * print_error - prints an error message
 * @info: the parameter & return info struct
 * @estr: string containing specified error type
 * Return: 0 if no numbers in string, converted number otherwise
 *        -1 on error
 */
void print_error(info_t *info, char *estr)
{
	_eputs(info->fname); /* Print file name */
	_eputs(": ");
	print_d(info->line_count, STDERR_FILENO); /* Print line count */
	_eputs(": ");
	_eputs(info->argv[0]); /* Print command name */
	_eputs(": ");
	_eputs(estr); /* Print error string */
}

/**
 * print_d - function prints a decimal number
 * @input: the input
 * @fd: the filedescriptor to write to
 *
 * Return: number of characters printed
 */
int print_d(int input, int fd)
{
	int (*__putchar)(char) = (fd == STDERR_FILENO) ? _eputchar : _putchar;
	int i, count = 0;
	unsigned int _abs_, current;

	if (input < 0)
	{
		_abs_ = -input;
		__putchar('-'); /* Print '-' sign for negative numbers */
		count++;
	}
	else
		_abs_ = input;
	current = _abs_;
	for (i = 1000000000; i > 1; i /= 10)
	{
		if (_abs_ / i)
		{
			__putchar('0' + current / i);/* Print each digit of the number */
			count++;
		}
		current %= i;
	}
	__putchar('0' + current); /* Print the last digit */
	count++;

	return (count); /* Return the number of characters printed */
}

/**
 * convert_number - converter function
 * @num: number
 * @base: base
 * @flags: argument
 *
 * Return: string
 */
char *convert_number(long int num, int base, int flags)
{
	static char *array;
	static char buffer[50];
	char sign = 0;
	char *ptr;
	unsigned long n = num;

	if (!(flags & CONVERT_UNSIGNED) && num < 0)
	{
		n = -num;
		sign = '-'; /* Set the sign character for negative numbers */

	}
	array = flags & CONVERT_LOWERCASE ? "0123456789abcdef" : "0123456789ABCDEF";
	ptr = &buffer[49];
	*ptr = '\0';

	do	{
		*--ptr = array[n % base];/*Convert each digit to corresponding character*/
		n /= base;
	} while (n != 0);

	if (sign)
		*--ptr = sign; /* Add the sign character if necessary */
	return (ptr); /* Return the resulting string */
}

/**
 * remove_comments - replaces first instance of '#' with '\0'
 * @buf: address of the string
 *
 * Return: Always 0;
 */
void remove_comments(char *buf)
{
	int i;

	for (i = 0; buf[i] != '\0'; i++)
		if (buf[i] == '#' && (!i || buf[i - 1] == ' '))
		{
			buf[i] = '\0'; /* Replace '#' with null character '\0' */
			break;
		}
}
