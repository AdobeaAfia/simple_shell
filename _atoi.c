#include "shell.h"

/**
 * interactive - program runs if shell is interactive mode
 * @info: struct address
 * Return: Succesful if 1 is interactive mode, 0 is not
 */

int interactive(info_t *info)
{
	return (isatty(STDIN_FILENO) && info->readfd <= 2);
}

/**
 *_isalpha - checks for alphabetic character
 *@s: The character to input
 *Return: Successful if is 1 = alphabetic, else 0
 */

int _isalpha(int s)
{
	if ((s >= 'a' && s <= 'z') || (s >= 'A' && s <= 'Z'))
		return (1);
	else
		return (0);
}

/**
 * is_delim - program checks if character is a delimeter
 * @s: the char to check
 * @delim: the delimeter string
 * Return: Successful when 1 is true, 0 if false
 */

int is_delim(char *s, char *delim)
{
	while (*delim)
	{
		if (*delim == *s)
			return (1);
		delim++;
	}
	return (0);
}

/**
 *_atoi - converts a string to an integer
 *@c: the string to be converted
 *Return: 0 if no numbers in string, converted number otherwise
 */

int _atoi(char *c)
{
	int b, sign = 1, flag = 0, output;
	unsigned int result = 0;

	for (b = 0;  c[b] != '\0' && flag != 2; b++)
	{
		if (c[b] == '-')
			sign *= -1;

		if (c[b] >= '0' && c[b] <= '9')
		{
			flag = 1;
			result *= 10;
			result += (c[b] - '0');
		}
		else if (flag == 1)
			flag = 2;
	}

	if (sign == -1)
		output = -result;
	else
		output = result;

	return (output);
}
