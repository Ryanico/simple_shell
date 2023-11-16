#include "shell.h"
#include "shell_data_header.h"
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
	len = strlen(datsh->av[0]) + strlen(ver_stng);
	len += strlen(datsh->args[0]) + strlen(message) + 4;
	err = malloc(sizeof(char) * (len + 1));
	if (err == 0)
	{
		free(err);
		free(ver_stng);
		return (NULL);
	}

	strcpy(err, datsh->av[0]);
	strcat(err, ": ");
	strcat(err, ver_stng);
	strcat(err, ": ");
	strcat(err, datsh->args[0]);
	strcat(err, message);
	strcat(err, "\0");
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
	len = strlen(datsh->av[0]) + strlen(ver_stng);
	len += strlen(datsh->args[0]) + 24;
	err = malloc(sizeof(char) * (len + 1));
	if (err == 0)
	{
		free(err);
		free(ver_stng);
		return (NULL);
	}
	strcpy(err, datsh->av[0]);
	strcat(err, ": ");
	strcat(err, ver_stng);
	strcat(err, ": ");
	strcat(err, datsh->args[0]);
	strcat(err, ": Permission denied\n");
	strcat(err, "\0");
	free(ver_stng);
	return (err);
}
