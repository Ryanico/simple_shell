#include "shell.h"

/**
 * rep_char - counts the repetitions of a char
 *
 * @input: input string
 * @h: index
 * Return: repetitions
 */
int rep_char(char *input, int h)
{
	if (*(input - 1) == *input)
		return (rep_char(input - 1, h + 1));

	return (h);
}

/**
 * error_sep_op - finds syntax errors
 *
 * @input: input string
 * @h: index
 * @l: last char read
 * Return: index of error. 0 when there are no errors
 */
int error_sep_op(char *input, int h, char l)
{
	int c;

	c = 0;
	if (*input == '\0')
		return (0);

	if (*input == ' ' || *input == '\t')
		return (error_sep_op(input + 1, h + 1, l));

	if (*input == ';')
		if (l == '|' || l == '&' || l == ';')
			return (h);

	if (*input == '|')
	{
		if (l == ';' || l == '&')
			return (h);

		if (l == '|')
		{
			c = rep_char(input, 0);
			if (c == 0 || c > 1)
				return (h);
		}
	}

	if (*input == '&')
	{
		if (l == ';' || l == '|')
			return (h);

		if (l == '&')
		{
			c = rep_char(input, 0);
			if (c == 0 || c > 1)
				return (h);
		}
	}

	return (error_sep_op(input + 1, h + 1, *input));
}

/**
 * f_char - finds index of the first char
 *
 * @input: input string
 * @h: index
 * Return: 1 if there is an error. 0 in other case.
 */
int f_char(char *input, int h)
{

	for (*h = 0; input[*h]; *h += 1)
	{
		if (input[*h] == ' ' || input[*h] == '\t')
			continue;

		if (input[*h] == ';' || input[*h] == '|' || input[*h] == '&')
			return (-1);

		break;
	}

	return (0);
}

/**
 * print_syntax_error - prints when a syntax error is found
 *
 * @datash: data structure
 * @input: input string
 * @h: index of the error
 * @bool: to control msg error
 * Return: no return
 */
void print_syntax_error(d_shell *datash, char *input, int h, int bool)
{
	char *msg, *msg2, *msg3, *error, *counter;
	int length;

	if (input[h] == ';')
	{
		if (bool == 0)
			msg = (input[h + 1] == ';' ? ";;" : ";");
		else
			msg = (input[h - 1] == ';' ? ";;" : ";");
	}

	if (input[h] == '|')
		msg = (input[h + 1] == '|' ? "||" : "|");

	if (input[h] == '&')
		msg = (input[h + 1] == '&' ? "&&" : "&");

	msg2 = ": Syntax error: \"";
	msg3 = "\" unexpected\n";
	counter = aux_itoa(datash->counter);
	length = _strlen(datash->av[0]) + _strlen(counter);
	length += _strlen(msg) + _strlen(msg2) + _strlen(msg3) + 2;

	error = malloc(sizeof(char) * (length + 1));
	if (error == 0)
	{
		free(counter);
		return;
	}
	_strcpy(error, datash->av[0]);
	_strcat(error, ": ");
	_strcat(error, counter);
	_strcat(error, msg2);
	_strcat(error, msg);
	_strcat(error, msg3);
	_strcat(error, "\0");

	write(STDERR_FILENO, error, length);
	free(error);
	free(counter);
}

/**
 * check_syntax_error - intermediate function to find and print a syntax error
 *
 * @datash: data structure
 * @input: input string
 * Return: 1 if there is an error. 0 in other case
 */
int check_syntax_error(d_shell *datash, char *input)
{
	int begin = 0;
	int f_char = 0;
	int h = 0;

	fir_char = f_char(input, &begin);
	if (fir_char == -1)
	{
		print_syntax_error(datash, input, begin, 0);
		return (1);
	}

	h = error_sep_op(input + begin, 0, *(input + begin));
	if (h != 0)
	{
		print_syntax_error(datash, input, begin + h, 1);
		return (1);
	}

	return (0);
}
