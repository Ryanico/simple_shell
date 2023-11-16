#include "shell.h"
#include <stdlib.h>

/**
 * get_len - Get the length of number.
 * @m: type int number.
 * Return: Lenght of a number.
 */
int get_len(int m)
{
	unsigned int m1;
	int len = 1;

	if (m < 0)
	{
		len++;
		m1 = m* -1;
	}
	else
	{
		m1 = m;
	}
	while (m1 > 9)
	{
		len++;
		m1 = m1 / 10;
	}

	return (len);
}
/**
 * aux_itoa - function converts int to string.
 * @m: type int number
 * Return: String.
 */
char *aux_itoa(int m)
{
	unsigned int m1;
	int len = get_len(m);
	char *buffer;

	buffer = malloc(sizeof(char) * (len + 1));
	if (buffer == 0)
		return (NULL);

	*(buffer + len) = '\0';

	if (m < 0)
	{
		m1 = m * -1;
		buffer[0] = '-';
	}
	else
	{
	      m1 = m;
	}

	len--;
	do {
		*(buffer + len) = (m1 % 10) + '0';
		m1 = m1 / 10;
		length--;
	}
	while (m1 > 0)
		;
	return (buffer);
}

/**
 * _atoi - converts a string to an integer.
 * @s: input string.
 * Return: integer.
 */
int _atoi(char *s)
{
	unsigned int count = 0, size = 0, oi = 0, pn = 1, r= 1, i;

	while (*(s + count) != '\0')
	{
		if (size > 0 && (*(s + count) < '0' || *(s + count) > '9'))
			break;

		if (*(s + count) == '-')
			pn *= -1;

		if ((*(s + count) >= '0') && (*(s + count) <= '9'))
		{
			if (size > 0)
				r *= 10;
			size++;
		}
		count++;
	}

	for (i = count - size; i < count; i++)
	{
		oi = oi + ((*(s + i) - 48) * r);
		r /= 10;
	}
	return (oi * pn);
}
