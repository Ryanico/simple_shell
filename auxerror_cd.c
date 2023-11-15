#include "shell.h"

/**
 * strconct_cd - function that concatenates the msg for cd error
 *
 * @datsh: data relevant "directory"
 * @message: message to print
 * @err: output message
 * @ver_stng: counter lines
 * Return: error message
 */
char *strconct_cd(shell_data *datsh, char *message, char *err, char *ver_stng)
{
	char *error_flag;

	_strcpy(err, datsh->av[0]);
	_strcat(err, ": ");
	_strcat(err, ver_stng);
	_strcat(err, ": ");
	_strcat(err, datsh->args[0]);
	_strcat(err, message);
	if (datsh->args[1][0] == '-')
	{
		error_flag = malloc(3);
		error_flag[0] = '-';
		error_flag[1] = datsh->args[1][1];
		error_flag[2] = '\0';
		_strcat(err, error_flag);
		free(error_flag);
	}
	else
	{
		_strcat(err, datsh->args[1]);
	}

	_strcat(err, "\n");
	_strcat(err, "\0");
	return (err);
}

/**
 * errorget_cd - error message for cd command in get_cd
 * @datsh: data relevant (directory)
 * Return: Error message
 */
char *errorget_cd(shell_data *datsh)
{
	int len, length_id;
	char *err, *ver_stng, *message;

	ver_stng = aux_itoa(datsh->counter);
	if (datsh->args[1][0] == '-')
	{
		message = ": Illegal option ";
		length_id = 2;
	}
	else
	{
		message = ": can't cd to ";
		length_id = _strlen(datsh->args[1]);
	}

	len = _strlen(datsh->av[0]) + _strlen(datsh->args[0]);
	len += _strlen(ver_stng) + _strlen(message) + length_id + 5;
	err = malloc(sizeof(char) * (len + 1));

	if (err == 0)
	{
		free(ver_stng);
		return (NULL);
	}

	err = strcat_cd(datsh, message, err, ver_stng);

	free(ver_stng);

	return (err);
}

/**
 * errornot_found - error message for command not found
 * @datsh: data relevant (counter, arguments)
 * Return: Error message
 */
char *errornot_found(shell_data *datsh)
{
	int len;
	char *err;
	char *ver_stng;

	ver_stng = aux_itoa(datsh->counter);
	len = _strlen(datsh->av[0]) + _strlen(ver_stng);
	len += _strlen(datsh->args[0]) + 16;
	err = malloc(sizeof(char) * (len + 1));
	if (err == 0)
	{
		free(err);
		free(ver_stng);
		return (NULL);
	}
	_strcpy(err, datsh->av[0]);
	_strcat(err, ": ");
	_strcat(err, ver_stng);
	_strcat(err, ": ");
	_strcat(err, datsh->args[0]);
	_strcat(err, ": not found\n");
	_strcat(err, "\0");
	free(ver_stng);
	return (err);
}

/**
 * errorexit_shell - error message for exit in get_exit
 * @datsh: data relevant (counter, arguments)
 *
 * Return: Error message
 */
char *errorexit_shell(shell_data *datsh)
{
	int len;
	char *err;
	char *ver_stng;

	ver_stng = aux_itoa(datsh->counter);
	len = _strlen(datsh->av[0]) + _strlen(ver_stng);
	len += _strlen(datsh->args[0]) + _strlen(datsh->args[1]) + 23;
	err = malloc(sizeof(char) * (len + 1));
	if (err == 0)
	{
		free(ver_stng);
		return (NULL);
	}
	_strcpy(err, datsh->av[0]);
	_strcat(err, ": ");
	_strcat(err, ver_stng);
	_strcat(err, ": ");
	_strcat(err, datsh->args[0]);
	_strcat(err, ": Illegal number: ");
	_strcat(err, datsh->args[1]);
	_strcat(err, "\n\0");
	free(ver_stng);

	return (err);
}
