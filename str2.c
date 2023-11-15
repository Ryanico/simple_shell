#include "shell.h"

/**
 * _strdup - duplicates a str in heap memory.
 * @s: Type char pointer str
 * Return: duplicated str
 */
char *_strdup(const char *s)
{
	char *new;
	size_t l;

	l = _strlen(s);
	new = malloc(sizeof(char) * (l + 1));
	if (new == NULL)
		return (NULL);
	_memcpy(new, s, l + 1);
	return (new);
}

/**
 * _strlen - Returns the length of a string.
 * @s: Type char pointer
 * Return: Always 0.
 */
int _strlen(const char *s)
{
	int l;

	for (l = 0; s[l] != 0; l++)
	{
	}
	return (l);
}

/**
 * cmp_chars - compare chars of strings
 * @str: input string.
 * @del: delimiter.
 *
 * Return: 1 if are equals, 0 if not.
 */
int cmp_chars(char str[], const char *del)
{
	unsigned int i, j, k;

	for (i = 0, k = 0; str[i]; i++)
	{
		for (j = 0; del[j]; j++)
		{
			if (str[i] == del[j])
			{
				k++;
				break;
			}
		}
	}
	if (i == k)
		return (1);
	return (0);
}

/**
 * _strtok - splits a string by some delimiter.
 * @str: input string.
 * @del: delimiter.
 *
 * Return: string splited.
 */
char *_strtok(char str[], const char *del)
{
	static char *splitted, *str_end;
	char *str_start;
	unsigned int i, bool;

	if (str != NULL)
	{
		if (cmp_chars(str, del))
			return (NULL);
		splitted = str; /*Store first address*/
		i = _strlen(str);
		str_end = &str[i]; /*Store last address*/
	}
	str_start = splitted;
	if (str_start == str_end) /*Reaching the end*/
		return (NULL);

	for (bool = 0; *splitted; splitted++)
	{
		/*Breaking loop finding the next token*/
		if (splitted != str_start)
			if (*splitted && *(splitted - 1) == '\0')
				break;
		/*Replacing delimiter for null char*/
		for (i = 0; del[i]; i++)
		{
			if (*splitted == del[i])
			{
				*splitted = '\0';
				if (splitted == str_start)
					str_start++;
				break;
			}
		}
		if (bool == 0 && *splitted) /*Str != Del*/
			bool = 1;
	}
	if (bool == 0) /*Str == Del*/
		return (NULL);
	return (str_start);
}

/**
 * _isdigit - defines if string passed is a number
 *
 * @s: input string
 * Return: 1 if string is a number. 0 in other case.
 */
int _isdigit(const char *s)
{
	unsigned int i;

	for (i = 0; s[i]; i++)
	{
		if (s[i] < 48 || s[i] > 57)
			return (0);
	}
	return (1);
}
