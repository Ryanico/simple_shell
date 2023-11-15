#include "shell.h"

/**
 * is_cd - checks ":" if is in the current directory.
 * @path: type char pointer char.
 * @h: type int pointer of index.
 * Return: 1 if the path is searchable in the cd, 0 otherwise.
 */
int is_cd(char *path, int *h)
{
	if (path[*h] == ':')
		return (1);

	while (path[*h] != ':' && path[*h])
	{
		*h += 1;
	}

	if (path[*h])
		*h += 1;

	return (0);
}

/**
 * _w - locates a command
 *
 * @cnm: command name
 * @_envir: environment variable
 * Return: location of the command.
 */
char *_w(char *cnm, char **_envir)
{
	char *path, *ptr_path, *token_path, *dir;
	int len_dir, len_cnm, h;
	struct stat st;

	path = _getenv("PATH", _envir);
	if (path)
	{
		ptr_path = _strdup(path);
		len_cnm = _strlen(cnm);
		token_path = _strtok(ptr_path, ":");
		h = 0;
		while (token_path != NULL)
		{
			if (is_cd(path, &h))
				if (stat(cnm, &st) == 0)
					return (cnm);
			len_dir = _strlen(token_path);
			dir = malloc(len_dir + len_cnm + 2);
			_strcpy(dir, token_path);
			_strcat(dir, "/");
			_strcat(dir, cnm);
			_strcat(dir, "\0");
			if (stat(dir, &st) == 0)
			{
				free(ptr_path);
				return (dir);
			}
			free(dir);
			token_path = _strtok(NULL, ":");
		}
		free(ptr_path);
		if (stat(cnm, &st) == 0)
			return (cnm);
		return (NULL);
	}
	if (cnm[0] == '/')
		if (stat(cnm, &st) == 0)
			return (cnm);
	return (NULL);
}

/**
 * is_exec - determines if is an executable
 *
 * @datash: data structure
 * Return: 0 if is not an executable, other number if it does
 */
int is_exec(d_shell *datash)
{
	struct stat st;
	int h;
	char *input;

	input = datash->args[0];
	for (h = 0; input[h]; h++)
	{
		if (input[h] == '.')
		{
			if (input[h + 1] == '.')
				return (0);
			if (input[h + 1] == '/')
				continue;
			else
				break;
		}
		else if (input[h] == '/' && h != 0)
		{
			if (input[h + 1] == '.')
				continue;
			h++;
			break;
		}
		else
			break;
	}
	if (h == 0)
		return (0);

	if (stat(input + h, &st) == 0)
	{
		return (h);
	}
	get_error(datash, 127);
	return (-1);
}

/**
 * check_error_cnm - verifies if user has permissions to access
 *
 * @dir: destination directory
 * @datash: data structure
 * Return: 1 if there is an error, 0 if not
 */
int check_error_cnm(char *dir, d_shell *datash)
{
	if (dir == NULL)
	{
		get_error(datash, 127);
		return (1);
	}

	if (_strcmp(datash->args[0], dir) != 0)
	{
		if (access(dir, X_OK) == -1)
		{
			get_error(datash, 126);
			free(dir);
			return (1);
		}
		free(dir);
	}
	else
	{
		if (access(datash->args[0], X_OK) == -1)
		{
			get_error(datash, 126);
			return (1);
		}
	}

	return (0);
}

/**
 * cnm_exec - executes command lines
 *
 * @datash: data relevant (args and input)
 * Return: 1 on success.
 */
int cnm_exec(d_shell *datash)
{
	pid_t pd;
	pid_t wpd;
	int state;
	int exec;
	char *dir;
	(void) wpd;

	exec = is_exec(datash);
	if (exec == -1)
		return (1);
	if (exec == 0)
	{
		dir = _which(datash->args[0], datash->_envir);
		if (check_error_cnm(dir, datash) == 1)
			return (1);
	}

	pd = fork();
	if (pd == 0)
	{
		if (exec == 0)
			dir = _which(datash->args[0], datash->_envir);
		else
			dir = datash->args[0];
		execve(dir + exec, datash->args, datash->_envir);
	}
	else if (pd < 0)
	{
		perror(datash->av[0]);
		return (1);
	}
	else
	{
		do {
			wpd = waitpid(pd, &state, WUNTRACED);
		} while (!WIFEXITED(state) && !WIFSIGNALED(state));
	}

	datash->status = state / 256;
	return (1);
}
