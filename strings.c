#include "main.h"

/**
 * _strdup - returns a pointer to a newly allocated space in memory
 *
 * @str: Input String
 *
 * Return: Returns null if string is not allocated or returns string allocated
 * in different mem location
 *
 */

char *_strdup(char *str)
{
	int size = 0, i = 0;
	char *newString;

	if (str == NULL)
		return (NULL);

	for (; str[size]; size++)
		;

	newString = (char *)malloc((size++) * sizeof(char));

	if (newString == NULL)
		return (NULL);

	else
	{
		for (i = 0; i < size; i++)
			newString[i] = str[i];
	}

	return (newString);
}

/**
 * _strlen - Counts the lenght of string
 *
 *
 * @s: Input string
 *
 * Return: Returns the value of the lenght var
 *
 */
int _strlen(char *s)
{
	int len = 0;

	while (*s != '\0')
	{
		s++;
		len++;
	}
	return (len);
}
/**
 * _strcpy - Copy strings
 * @dest: Copy string location
 * @src: Input string
 * Return: String copy location
 */
char *_strcpy(char *dest, char *src)
{
	int i;

	for (i = 0; src[i]; i++)
		dest[i] = src[i];
	dest[i] = src[i];
	return (dest);
}

/**
 * _strcat - Print characters
 * @dest: Input string 1
 * @src: Input string 2
 * Return: Concatenated strings
 */

char *_strcat(char *dest, char *src)
{
	int len = _strlen(dest);
	int i = 0;

	for (i = 0; src[i]; i++, len++)
		dest[len] = src[i];

	return (dest);
}
/**
* _strncmp - compares two strings
* @s1: string
* @s2: string
* @n: numbers of bytes
*Return: comp
*/

int _strncmp(char *s1, char *s2, int n)
{
	int i = 0;
	int comp = 0;

	if (i < n)
	{
		while (s1[i] && s2[i])
		{
			if (s1[i] == s2[i])
			{
				comp = 0;
				i++;
			}
			else
			{
				comp = s1[i] - s2[i];
				break;
			}
		}
	}
	return (comp);
}
