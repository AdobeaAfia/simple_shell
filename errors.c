#include "shell.h"

/**
 *_eputs - program prints an input string
 * @str: the string to be printed
 * Return: Nothing
 */

void _eputs(char *str)
{
	int k = 0;

	if (!str)
		return;
	while (str[k] != '\0')
	{
		_eputchar(str[k]);
		k++;
	}
}

/**
 *_putsfd - program prints an input string
 * @str: the string to be printed
 * @fd: the filedescriptor
 * Return: the number of chars
 */

int _putsfd(char *str, int fd)
{
	int k = 0;

	if (!str)
		return (0);
	while (*str)
	{
		k += _putfd(*str++, fd);
	}
	return (k);
}

/**
 * _eputchar - program writes the character c to stderr
 * @c: The character to print
 * Return: Successful when 1.
 * On error, -1 is returned.
 */

int _eputchar(char c)
{
	static int k;
	static char buffer[WRITE_BUF_SIZE];

	if (c == BUF_FLUSH || k >= WRITE_BUF_SIZE)
	{
		write(2, buffer, k);
		k = 0;
	}
	if (c != BUF_FLUSH)
		buffer[k++] = c;
	return (1);
}

/**
 * _putfd - program writes the character c to a given fd
 * @c: The character to printed
 * @fd: The filedescriptor
 * Return: On success 1.
 * On error, -1 is returned.
 */

int _putfd(char c, int fd)
{
	static int k;
	static char buffer[WRITE_BUF_SIZE];

	if (c == BUF_FLUSH || k >= WRITE_BUF_SIZE)
	{
		write(fd, buffer, k);
		k = 0;
	}
	if (c != BUF_FLUSH)
		buffer[k++] = c;
	return (1);
}
