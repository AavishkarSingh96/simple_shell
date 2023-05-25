#include "shell.h"

/**
 * _erratoi - string to integer conversion
 * @s: the string
 * Return: converted number on success, -1 on error
 */
int _erratoi(char *s)
{
	int i = 0;
	unsigned long int result = 0;

	if (*s == '+')
		s++; /* Skip leading '+' if present */

	for (i = 0; s[i] != '\0'; i++)
	{
		if (s[i] >= '0' && s[i] <= '9') /* Check if character is a digit */
		{
			result *= 10;
			result += (s[i] - '0'); /* Convert character to numeric value */
			if (result > INT_MAX)
				return (-1); /* Return -1 if number exceeds INT_MAX */
		}
		else
			return (-1); /* Return -1 if non-digit character found */
	}

	return (result); /* Return the converted number */
}

/**
 * print_error - prints an error message
 * @info: parameter & return info struct
 * @estr: string containing specified error type
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
 * print_d - prints a decimal (integer) number (base 10)
 * @input: the input
 * @fd: file descriptor to write to
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
			__putchar('0' + current / i); /* Print each digit of the number */
			count++;
		}
		current %= i;
	}
	__putchar('0' + current); /* Print the last digit */
	count++;

	return (count); /* Return the number of characters printed */
}

/**
 * convert_number - converts a number to a string
 * @num: number
 * @base: base
 * @flags: argument flags
 * Return: string representation of the number
 */
char *convert_number(long int num, int base, int flags)
{
	static char buffer[50];
	char sign = 0;
	char *ptr;
	unsigned long n = num;
	const char *array = (flags & CONVERT_LOWERCASE) ? "0123456789abcdef" :
	"0123456789ABCDEF";

	if (!(flags & CONVERT_UNSIGNED) && num < 0)
	{
		n = -num;
		sign = '-'; /* Set the sign character for negative numbers */
	}

	ptr = &buffer[49];
	*ptr = '\0';

	do {
		*--ptr = array[n % base];
		/* Convert each digit to the corresponding character */
		n /= base;
	} while (n != 0);

	if (sign)
		*--ptr = sign; /* Add the sign character if necessary */

	return (ptr); /* Return the resulting string */
}

/**
 * remove_comments - replaces first instance of '#' with '\0'
 * @buf: address of the string to modify
 */
void remove_comments(char *buf)
{
	int k;

	for (k = 0; buf[k] != '\0'; k++)
	{
		if (buf[k] == '#' && (!k || buf[k - 1] == ' '))
		{
			buf[k] = '\0'; /* Replace # with null character '\0' */
			break;
		}
	}
}
