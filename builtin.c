#include "shell.h"

/**
 * _myexit - code exits the shell
 * @info: Contains all  potential arguments used
 * to maintain constant function prototype.
 * Return: Successful when exit argument == 0 if info.argv[0] != "exit"
 */

int _myexit(info_t *info)
{
	int exitchecks;

	if (info->argv[1])
	{
		exitchecks = _erratoi(info->argv[1]);
		if (exitchecks == -1)
		{
			info->status = 2;
			print_error(info, "Illegal number: ");
			_eputs(info->argv[1]);
			_eputchar('\n');
			return (1);
		}
		info->err_num = _erratoi(info->argv[1]);
		return (-2);
	}
	info->err_num = -1;
	return (-2);
}

/**
 * _myhelp - programs changes the current directory
 * @info: Structure contains potential arguments.
 *  Return: Always Successful when 0
 */

int _myhelp(info_t *info)
{
	char **arg_array;

	arg_array = info->argv;
	_puts("help when call works. Function not yet implemented \n");
	if (0)
		_puts(*arg_array);
	return (0);
}

/**
 * _mycd - code changes current directory
 * @info: Contains potential arguments.
 *  Return: Succesful always when 0
 */

int _mycd(info_t *info)
{
	char *s, *dire, buffer[1024];
	int chdir_ret;

	s = getcwd(buffer, 1024);
	if (!s)
		_puts("TODO: >>getcwd failure emsg here<<\n");
	if (!info->argv[1])
	{
		dire = _getenv(info, "HOME=");
		if (!dire)
			chdir_ret = /* TODO: what should this be? */
				chdir((dire = _getenv(info, "PWD=")) ? dire : "/");
		else
			chdir_ret = chdir(dire);
	}
	else if (_strcmp(info->argv[1], "-") == 0)
	{
		if (!_getenv(info, "OLDPWD="))
		{
			_puts(s);
			_putchar('\n');
			return (1);
		}
		_puts(_getenv(info, "OLDPWD=")), _putchar('\n');
		chdir_ret = /* TODO: what should this be? */
			chdir((dire = _getenv(info, "OLDPWD=")) ? dire : "/");
	}
	else
		chdir_ret = chdir(info->argv[1]);
	if (chdir_ret == -1)
	{
		print_error(info, "can't cd to ");
		_eputs(info->argv[1]), _eputchar('\n');
	}
	else
	{
		_setenv(info, "OLDPWD", _getenv(info, "PWD="));
		_setenv(info, "PWD", getcwd(buffer, 1024));
	}
	return (0);
}
