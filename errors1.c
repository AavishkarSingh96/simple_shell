#include "shell.h"

/**
<<<<<<< HEAD
 * _erratoi - string to int conversion
 * @s: string
 * Return: 0 no numbers in string, converted number else
 * -1 on error
=======
 * mouse - string to integer
 * @moon: the string converted
 * Return: 0 if no numbers, converted number otherwise
 *       -1 on error
>>>>>>> d7febdd3e596410343bf9d607f99b57a080e46b7
 */
int mouse(char *moon)
{
	int sun = 0;
	unsigned long int result = 0;
<<<<<<< HEAD

	if (*s == '+')
		s++; /* Skip leading + if present */
	for (i = 0;  s[i] != '\0'; i++)
	{
		if (s[i] >= '0' && s[i] <= '9') /*Check if character is digit*/
		{
			result *= 10;
			result += (s[i] - '0'); /*Convert character to number*/
=======
/*c language used*/
	if (*moon == '+')
		moon++;  /* TODO: why does this make main return 255? */
	for (sun = 0;  moon[sun] != '\0'; sun++)
/*to do comment inserted*/
	{
		if (moon[sun] >= '0' && moon[sun] <= '9')
		{
			result *= 10;
			result += (moon[sun] - '0');
>>>>>>> d7febdd3e596410343bf9d607f99b57a080e46b7
			if (result > INT_MAX)
				return (-1); /*Return -1, num exceeds INT_MAX*/
		}
		else
			return (-1); /* Return -1 if non-digit character found */
	}
	return (result); /* Return the converted number */
}
/*random number is used*/
/**
 * jam - prints an error message
 * @note: parameter & return info
 * @pig: specified error type string
 * Return: 0 if no numbers in string, converted number otherwise
 *        -1 on error
 */
void jam(note_t *note, char *pig)
{
<<<<<<< HEAD
	_eputs(info->fname); /* Print file name */
	_eputs(": ");
	print_d(info->line_count, STDERR_FILENO); /* Print line count */
	_eputs(": ");
	_eputs(info->argv[0]); /* Print command name */
	_eputs(": ");
	_eputs(estr); /* Print error string */
=======
	_eputs(note->fname);
	_eputs(": ");
	print_d(note->line_count, STDERR_FILENO);
	_eputs(": ");
	_eputs(note->argv[0]);
	_eputs(": ");
	_eputs(pig);
>>>>>>> d7febdd3e596410343bf9d607f99b57a080e46b7
}
/*why remove comments*/
/**
<<<<<<< HEAD
 * print_d - function prints a decimal number
 * @input: the input
 * @fd: the filedescriptor to write to
 *
=======
 * news - prints a decimal(base 10)
 * @start: the input
 * @gta: filedescriptor
 *c is really hard
>>>>>>> d7febdd3e596410343bf9d607f99b57a080e46b7
 * Return: number of characters printed
 */
int news(int start, int gta)
{
<<<<<<< HEAD
	int (*__putchar)(char) = (fd == STDERR_FILENO) ? _eputchar : _putchar;
	int i, count = 0;
	unsigned int _abs_, current;

	if (input < 0)
	{
		_abs_ = -input;
		__putchar('-'); /* Print '-' sign for negative numbers */
		count++;
=======
	int (*__putchar)(char) = _putchar;
	int abc, xyz = 0;
	unsigned int _abs_, current;

	if (gta == STDERR_FILENO)
		__putchar = _eputchar;
	if (start < 0)
	{
		_abs_ = -start;
		__putchar('-');
		xyz++;
>>>>>>> d7febdd3e596410343bf9d607f99b57a080e46b7
	}
	else
		_abs_ = start;
	current = _abs_;
	for (abc = 1000000000; abc > 1; abc /= 10)
	{
		if (_abs_ / abc)
		{
<<<<<<< HEAD
			__putchar('0' + current / i);/* Print each digit of the number */
			count++;
=======
			__putchar('0' + current / abc);
			xyz++;
>>>>>>> d7febdd3e596410343bf9d607f99b57a080e46b7
		}
		current %= abc;
	}
<<<<<<< HEAD
	__putchar('0' + current); /* Print the last digit */
	count++;

	return (count); /* Return the number of characters printed */
=======
	__putchar('0' + current);
	xyz++;
/*this is a long code*/
	return (xyz);
>>>>>>> d7febdd3e596410343bf9d607f99b57a080e46b7
}
/*hopefully the last section*/
/**
<<<<<<< HEAD
 * convert_number - converter function
 * @num: number
 * @base: base
 * @flags: argument
 *
=======
 * dolly - clone of itoa
 * @digit: number
 * @acid: base
 * @red: argument flags
 *this is cool
>>>>>>> d7febdd3e596410343bf9d607f99b57a080e46b7
 * Return: string
 */
char *dolly(long int digit, int acid, int red)
/*A space for neatness*/
{
	static char *array;
	static char buffer[50];
	char sign = 0;
	char *sylar;
	unsigned long x = digit;
/*a break inserted*/
	if (!(red & CONVERT_UNSIGNED) && digit < 0)
	{
<<<<<<< HEAD
		n = -num;
		sign = '-'; /* Set the sign character for negative numbers */
=======
		x = -digit;
/*x is equal to*/
		sign = '-';
>>>>>>> d7febdd3e596410343bf9d607f99b57a080e46b7

	}
	array = red & CONVERT_LOWERCASE ? "0123456789abcdef" : "0123456789ABCDEF";
	sylar = &buffer[49];
	*sylar = '\0';
/*coding feels like magic*/
	do	{
<<<<<<< HEAD
		*--ptr = array[n % base];/*Convert each digit to corresponding character*/
		n /= base;
	} while (n != 0);

	if (sign)
		*--ptr = sign; /* Add the sign character if necessary */
	return (ptr); /* Return the resulting string */
=======
		*--sylar = array[x % acid];
		x /= acid;
	} while (x != 0);
/*liken coding to x solve*/
	if (sign)
		*--sylar = sign;
	return (sylar);
>>>>>>> d7febdd3e596410343bf9d607f99b57a080e46b7
}
/*another space here*/
/**
<<<<<<< HEAD
 * remove_comments - replaces first instance of '#' with '\0'
 * @buf: address of the string
 *
=======
 * rcm - function replaces first instance of '#' with '\0'
 * @strmod: string to modify
 *does the code work
>>>>>>> d7febdd3e596410343bf9d607f99b57a080e46b7
 * Return: Always 0;
 */
void rcm(char *strmod)
{
	int aa;
/*used aa instead*/
	for (aa = 0; strmod[aa] != '\0'; aa++)
		if (buf[aa] == '#' && (!aa || strmod[aa - 1] == ' '))
		{
<<<<<<< HEAD
			buf[i] = '\0'; /* Replace '#' with null character '\0' */
=======
			strmod[aa] = '\0';
>>>>>>> d7febdd3e596410343bf9d607f99b57a080e46b7
			break;
		}
}
