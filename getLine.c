#include "shell.h"

/**
 * chainz - buffers chained commands
 * @square: parameter struct
 * @john: address of buffer
 * @amy: address of len var
 *
 * Return: bytes read
 */
ssize_t chainz(square_t *square, char **john, size_t *amy)
{
	ssize_t op = 0;
	size_t amy_d = 0;
/*still the first section*/
	if (!*amy) /* if nothing left in the buffer, fill it */
	{
		/*bfree((void **)square->cmd_john);*/
		free(*john);
		*john = NULL;
		signal(SIGINT, sigintHandler);
#if USE_GETLINE
		op = getline(john, &amy_d, stdin);
#else
		op = _getline(square, john, &amy_d);
#endif
		if (op > 0)
		{
			if ((*john)[op - 1] == '\n')
			{
				(*john)[op - 1] = '\0'; /* remove trailing newline */
				op--;
			}
			square->linecount_flag = 1;
			remove_comments(*john);
			build_history_list(square, *john, square->histcount++);
			/* if (_strchr(*buf, ';')) is this a command chain? */
			{
				*amy = op;
				square->cmd_john = john;
			}
		}
	}
	return (op);
}
/*try to be consistent*/
/**
 * altern - gets a line minus the newline
 * @square: parameter struct
 *this is c language
 * Return: bytes read
 */
ssize_t get_input(info_t *info)
{
	static char *john; /* the ';' command chain buffer */
	static size_t a, b, amy;
	ssize_t op = 0;
	char **john_d = &(square->arg), *d;
/*this is the third section*/
	_putchar(BUF_FLUSH);
	op = input_john(square, &john, &amy);
	if (op == -1) /* EOF */
		return (-1);
	if (amy) /* we have commands left in the chain buffer */
	{
		b = a; /* init new iterator to current buf position */
		d = john + a; /* get pointer for return */
/*this is progressing*/
		check_chain(square, john, &b, a, amy);
		while (b < amy) /* iterate to semicolon or end */
		{
			if (is_chain(square, john, &b))
				break;
			b++;
		}
/*remember to take stock*/
		a = b + 1; /* increment past nulled ';'' */
		if (i >= len) /* reached end of buffer? */
		{
			i = len = 0; /* reset position and length */
			info->cmd_buf_type = CMD_NORM;
		}

		*buf_p = p; /* pass back pointer to current command position */
		return (_strlen(p)); /* return length of current command */
	}

	*buf_p = buf; /* else not a chain, pass back buffer from _getline() */
	return (r); /* return length of buffer from _getline() */
}

/**
 * read_buf - reads a buffer
 * @info: parameter struct
 * @buf: buffer
 * @i: size
 *
 * Return: r
 */
ssize_t read_buf(info_t *info, char *buf, size_t *i)
{
	ssize_t r = 0;

	if (*i)
		return (0);
	r = read(info->readfd, buf, READ_BUF_SIZE);
	if (r >= 0)
		*i = r;
	return (r);
}

/**
 * _getline - gets the next line of input from STDIN
 * @info: parameter struct
 * @ptr: address of pointer to buffer, preallocated or NULL
 * @length: size of preallocated ptr buffer if not NULL
 *
 * Return: s
 */
int _getline(info_t *info, char **ptr, size_t *length)
{
	static char buf[READ_BUF_SIZE];
	static size_t i, len;
	size_t k;
	ssize_t r = 0, s = 0;
	char *p = NULL, *new_p = NULL, *c;

	p = *ptr;
	if (p && length)
		s = *length;
	if (i == len)
		i = len = 0;

	r = read_buf(info, buf, &len);
	if (r == -1 || (r == 0 && len == 0))
		return (-1);

	c = _strchr(buf + i, '\n');
	k = c ? 1 + (unsigned int)(c - buf) : len;
	new_p = _realloc(p, s, s ? s + k : k + 1);
	if (!new_p) /* MALLOC FAILURE! */
		return (p ? free(p), -1 : -1);

	if (s)
		_strncat(new_p, buf + i, k - i);
	else
		_strncpy(new_p, buf + i, k - i + 1);

	s += k - i;
	i = k;
	p = new_p;

	if (length)
		*length = s;
	*ptr = p;
	return (s);
}

/**
 * sigintHandler - blocks ctrl-C
 * @sig_num: the signal number
 *
 * Return: void
 */
void sigintHandler(__attribute__((unused))int sig_num)
{
	_puts("\n");
	_puts("$ ");
	_putchar(BUF_FLUSH);
}
/*you lose*/
