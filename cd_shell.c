#include "shell.h"

/**
 * cd_shell - changes current directory
 *
 * @datash: data relevant
 * Return: 1 on success
 */
int cd_shell(d_shell *datash)
{
	char *d;
	int home, home2, dash;

	d = datash->args[1];

	if (d != NULL)
	{
		home = _strcmp("$HOME", d);
		home2 = _strcmp("~", d);
		dash = _strcmp("--", d);
	}

	if (d == NULL || !home || !home2 || !dash)
	{
		cd_to_home(datash);
		return (1);
	}

	if (_strcmp("-", d) == 0)
	{
		cd_previous(datash);
		return (1);
	}

	if (_strcmp(".", d) == 0 || _strcmp("..", d) == 0)
	{
		cd_dot(datash);
		return (1);
	}

	cd_to(datash);

	return (1);
}
