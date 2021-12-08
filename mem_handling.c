#include "main.h"

/**
 * _realloc - reallocates space in memory and
 * frees the previosly allocated mem
 * @ptr: entry allocated pointer
 * @old_size: old size in bytes
 * @new_size: new size in bytes
 * Return: pointer reallocated in mem
 */

void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
	char *ptr2;
	unsigned int i = 0;

	if (ptr == NULL)
	{
		free(ptr);
		return (malloc(new_size));
	}

	if (old_size == new_size)
		return (ptr);
	if (new_size == 0 && ptr != NULL)
	{
		free(ptr);
		return (NULL);
	}

	ptr2 = malloc(new_size);
	if (ptr2 == NULL)
	{
		free(ptr);
		return (NULL);
	}

	if (old_size < new_size)
	{
		for (i = 0; i < old_size; i++)
		{
			*(ptr2 + i) = *((char *)ptr + i);
		}
	}
	free(ptr);

	return (ptr2);
}

/**
 * free_elements - frees elements
 * @free1: pointer to string
 * @free2: double pointer to string
 */

void free_elements(char *free1, char **free2)
{
	free(free1);
	free(free2);
}
