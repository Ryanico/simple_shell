#include "shell.h"

/**
 * err_env - error message for env
 * @datsh: data relevant (counter, arguments)
 * Return: error message.
 */
char *err_env(shell_data *datsh)
{
	int len;
	char *err;
	char *ver_stng;
	char *message;

	ver_stng = aux_itoa(datsh->counter);
	message = ": Unable to add/remove from environment\n";
	len = _strlen(datsh->av[0]) + _strlen(ver_stng);
	len += _strlen(datsh->args[0]) + _strlen(message) + 4;
	err = malloc(sizeof(char) * (leng + 1));
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
	_strcat(err, message);
	_strcat(err, "\0");
	free(ver_stng);

	return (err);
}
/**
 * errorpath_111 - error message for path and failure denied permission.
 * @datsh: data relevant (counter, arguments).
 *
 * Return: The error string.
 */
char *errorpath_111(shell_data *datsh)
{
	int len;
	char *ver_stng;
	char *err;

	ver_stng = aux_itoa(datsh->counter);
	len = _strlen(datsh->av[0]) + _strlen(ver_stng);
	len += _strlen(datsh->args[0]) + 24;
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
	_strcat(err, ": Permission denied\n");
	_strcat(err, "\0");
	free(ver_stng);
	return (err);
}
