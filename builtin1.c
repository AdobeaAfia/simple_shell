#include "shell.h"

/**
 * _myhistory - program displays the history list.
 * @info: Structure contains potential arguments.
 * Return: Successful when 0
 */

int _myhistory(info_t *info)
{
	print_list(info->history);
	return (0);
}

/**
 * unset_alias - program sets alias to string
 * @info: parameter struct
 * @str: the string alias
 * Return: Successful when 0, 1 on error
 */

int unset_alias(info_t *info, char *str)
{
	char *c, k;
	int ret;

	c = _strchr(str, '=');
	if (!c)
		return (1);
	k = *c;
	*c = 0;
	ret = delete_node_at_index(&(info->alias),
		get_node_index(info->alias, node_starts_with(info->alias, str, -1)));
	*c = k;
	return (ret);
}

/**
 * set_alias - programs sets alias to string
 * @info: parameter struct
 * @str: the string alias
 * Return: Always 0 on success, 1 on error
 */

int set_alias(info_t *info, char *str)
{
	char *c;

	c = _strchr(str, '=');
	if (!c)
		return (1);
	if (!*++c)
		return (unset_alias(info, str));

	unset_alias(info, str);
	return (add_node_end(&(info->alias), str, 0) == NULL);
}

/**
 * print_alias - programs prints an alias string
 * @node: the alias node
 * Return: Always 0 on success, 1 on error
 */

int print_alias(list_t *node)
{
	char *c = NULL, *b = NULL;

	if (node)
	{
		c = _strchr(node->str, '=');
		for (b = node->str; b <= c; b++)
			_putchar(*b);
		_putchar('\'');
		_puts(c + 1);
		_puts("'\n");
		return (0);
	}
	return (1);
}

/**
 * _myalias - program mimics the alias builtin
 * @info: Structure contains potential arguments.
 * Return: Always 0 when successful
 */

int _myalias(info_t *info)
{
	int k = 0;
	char *c = NULL;
	list_t *node = NULL;

	if (info->argc == 1)
	{
		node = info->alias;
		while (node)
		{
			print_alias(node);
			node = node->next;
		}
		return (0);
	}

	for (k = 1; info->argv[k]; k++)
		;
	if (c)
		set_alias(info, info->argv[k]);
	else
	{
		node = node_starts_with(info->alias, info->argv[k], '=');
		if (node)
			print_alias(node);
	}
	return (0);
}
