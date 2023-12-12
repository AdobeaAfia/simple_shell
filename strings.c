#include "shell.h"

/**
 * _strcpy - program copies a string
 * @dest: the destination
 * @src: the source
 * Return: the pointer to destination
 */

char *_strcpy(char *dest, char *src)
{
	int b = 0;

	if (dest == src || src == 0)
		return (dest);
	while (src[b])
	{
		dest[b] = src[b];
		b++;
	}
	dest[b] = 0;
	return (dest);
}

/**
 * _puts - prints an input string
 * @str: the string to be printed
 * Return: Nothing
 */

void _puts(char *str)
{
	int b = 0;

	if (!str)
		return;
	while (str[b] != '\0')
	{
		_putchar(str[b]);
		b++;
	}
}

/**
 * _strdup - program duplicates a string
 * @str: the string to duplicate
 * Return: pointer to the duplicated string
 */

char *_strdup(const char *str)
{
	int length = 0;
	char *ret;

	if (str == NULL)
		return (NULL);
	while (*str++)
		length++;
	ret = malloc(sizeof(char) * (length + 1));
	if (!ret)
		return (NULL);
	for (length++; length--;)
		ret[length] = *--str;
	return (ret);
}

/**
 * _putchar - program writes the character c to stdout
 * @c: The character to print
 * Return: Successful on 1, else On error, -1 is returned.
 */

int _putchar(char c)
{
	static int b;
	static char buf[WRITE_BUF_SIZE];

	if (c == BUF_FLUSH || b >= WRITE_BUF_SIZE)
	{
		write(1, buf, b);
		b = 0;
	}
	if (c != BUF_FLUSH)
		buf[b++] = c;
	return (1);
}