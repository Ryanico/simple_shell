#include "shell.h"

/**
 * adds_sep_node_end - adds a separator found at the end
 * of a sep_lists.
 * @Head: head of the linked list.
 * @Sep: separator found (; | &).
 * Return: address of the head.
 */
sep_lists *adds_sep_node_end(sep_lists **Head, char Sep)
{
	sep_lists *New, *Temp;

	New = malloc(sizeof(sep_lists));
	if (New == NULL)
		return (NULL);

	New->separator = Sep;
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
 * free_sep_lists - frees a sep_lists
 * @Head: head of the linked list.
 * Return: no return.
 */
void free_sep_lists(sep_lists **Head)
{
	sep_lists *Temp;
	sep_lists *currs;

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

/**
 * adds_line_node_end - adds a command line at the end
 * of a line_lists.
 * @Head: head of the linked list.
 * @Line: command line.
 * Return: address of the head.
 */
line_lists *adds_line_node_end(line_lists **Head, char *Line)
{
	line_lists *New, *Temp;

	New = malloc(sizeof(line_lists));
	if (New == NULL)
		return (NULL);

	New->line = Line;
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
 * frees_line_list - frees a line_lists
 * @Head: head of the linked list.
 * Return: no return.
 */
void frees_line_list(line_lists **Head)
{
	line_lists *Temp;
	line_lists *currs;

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
