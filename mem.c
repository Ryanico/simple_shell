#include "shell.h"

/**
 * _memscpy - copies information between void pointers.
 * @Newptrs: destination pointer.
 * @ptrs: source pointer.
 * @Size: size of the new pointer.
 *
 * Return: no return.
 */
void _memscpy(void *Newptrs, const void *ptrs, unsigned int Size)
{
	char *char_ptrs = (char *)ptrs;
	char *char_Newptrs = (char *)Newptrs;
	unsigned int z;

	for (z = 0; z < Size; z++)
		char_Newptrs[z] = char_ptrs[z];
}

/**
 * _reallocs - reallocates a memory block.
 * @ptrs: pointer to the memory previously allocated.
 * @old_Size: size, in bytes, of the allocated space of ptr.
 * @new_Size: new size, in bytes, of the new memory block.
 *
 * Return: ptrs.
 * if new_Size == old_Size, returns ptrs without changes.
 * if malloc fails, returns NULL.
 */
void *_reallocs(void *ptrs, unsigned int old_Size, unsigned int new_Size)
{
	void *Newptrs;

	if (ptrs == NULL)
		return (malloc(new_Size));

	if (new_Size == 0)
	{
		free(ptrs);
		return (NULL);
	}

	if (new_Size == old_Size)
		return (ptrs);

	Newptrs = malloc(new_Size);
	if (Newptrs == NULL)
		return (NULL);

	if (new_Size < old_Size)
		_memscpy(Newptrs, ptrs, new_Size);
	else
		_memscpy(Newptrs, ptrs, old_Size);

	free(ptrs);
	return (Newptrs);
}

/**
 * _reallocsdp - reallocates a memory block of a double pointer.
 * @ptrs: double pointer to the memory previously allocated.
 * @old_Size: size, in bytes, of the allocated space of ptr.
 * @new_Size: new size, in bytes, of the new memory block.
 *
 * Return: ptrs.
 * if new_Size == old_Size, returns ptrs without changes.
 * if malloc fails, returns NULL.
 */
char **_reallocsdp(char **ptrs, unsigned int old_Size, unsigned int new_Size)
{
	char **Newptrs;
	unsigned int z;

	if (ptrs == NULL)
		return (malloc(sizeof(char *) * new_Size));

	if (new_Size == old_Size)
		return (ptrs);

	Newptrs = malloc(sizeof(char *) * new_Size);
	if (Newptrs == NULL)
		return (NULL);

	for (z = 0; z < old_Size; z++)
		Newptrs[z] = ptrs[z];

	free(ptrs);

	return (Newptrs);
}
