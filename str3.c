#include "shell.h"

/**
 * rev_string - reverses a string.
 * @st: input string.
 * Return: no return.
 */
void rev_string(char *st)
{
	int count = 0, i, j;
	char *str, temp;

	while (count >= 0)
	{
		if (st[count] == '\0')
			break;
		count++;
	}
	str = st;

	for (i = 0; i < (count - 1); i++)
	{
		for (j = i + 1; j > 0; j--)
		{
			temp = *(str + j);
			*(str + j) = *(str + (j - 1));
			*(str + (j - 1)) = temp;
		}
	}
}
