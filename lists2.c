#include "shell.h"

/**
 * adds_rvar_node - adds a variable at the end
 * of a r_vars list.
 * @Head: head of the linked list.
 * @lvars: length of the variable.
 * @vals: value of the variable.
 * @lvals: length of the value.
 * Return: address of the head.
 */
r_vars *adds_rvar_node(r_vars **Head, int lvars, char *vals, int lvals)
{
	r_vars *New, *Temp;

	New = malloc(sizeof(r_vars));
	if (New == NULL)
		return (NULL);

	New->len_var = lvars;
	New->vals = vals;
	New->len_val = lvals;

	New->next = NULL;
	Temp = *Head;

	if (Temp == NULL)
	{
		*Head = New;
	}
	else
	{
		while (Temp->next != NULL)
			Temp = Temp->next;
		Temp->next = New;
	}

	return (*Head);
}

/**
 * frees_rvar_list - frees a r_vars list
 * @Head: head of the linked list.
 * Return: no return.
 */
void frees_rvar_list(r_vars **Head)
{
	r_vars *Temp;
	r_vars *currs;

	if (Head != NULL)
	{
		currs = *Head;
		while ((Temp = currs) != NULL)
		{
			currs = currs->next;
			free(Temp);
		}
		*Head = NULL;
	}
}
