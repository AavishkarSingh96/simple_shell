#include "shell.h"

/**
 * mouse - string to integer
 * @moon: the string converted
 * Return: 0 if no numbers, converted number otherwise
 *       -1 on error
 */
int mouse(char *moon)
{
	int sun = 0;
	unsigned long int result = 0;
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
			if (result > INT_MAX)
				return (-1);
		}
		else
			return (-1);
	}
	return (result);
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
	_eputs(note->fname);
	_eputs(": ");
	print_d(note->line_count, STDERR_FILENO);
	_eputs(": ");
	_eputs(note->argv[0]);
	_eputs(": ");
	_eputs(pig);
}
/*why remove comments*/
/**
 * news - prints a decimal(base 10)
 * @start: the input
 * @gta: filedescriptor
 *c is really hard
 * Return: number of characters printed
 */
int news(int start, int gta)
{
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
	}
	else
		_abs_ = start;
	current = _abs_;
	for (abc = 1000000000; abc > 1; abc /= 10)
	{
		if (_abs_ / abc)
		{
			__putchar('0' + current / abc);
			xyz++;
		}
		current %= abc;
	}
	__putchar('0' + current);
	xyz++;
/*this is a long code*/
	return (xyz);
}
/*hopefully the last section*/
/**
 * dolly - clone of itoa
 * @digit: number
 * @acid: base
 * @red: argument flags
 *this is cool
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
		x = -digit;
/*x is equal to*/
		sign = '-';

	}
	array = red & CONVERT_LOWERCASE ? "0123456789abcdef" : "0123456789ABCDEF";
	sylar = &buffer[49];
	*sylar = '\0';
/*coding feels like magic*/
	do	{
		*--sylar = array[x % acid];
		x /= acid;
	} while (x != 0);
/*liken coding to x solve*/
	if (sign)
		*--sylar = sign;
	return (sylar);
}
/*another space here*/
/**
 * rcm - function replaces first instance of '#' with '\0'
 * @strmod: string to modify
 *does the code work
 * Return: Always 0;
 */
void rcm(char *strmod)
{
	int aa;
/*used aa instead*/
	for (aa = 0; strmod[aa] != '\0'; aa++)
		if (buf[aa] == '#' && (!aa || strmod[aa - 1] == ' '))
		{
			strmod[aa] = '\0';
			break;
		}
}
/*did he get fired*/
