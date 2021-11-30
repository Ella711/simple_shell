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

char *look_for_path(char **env)
{
	int i = 0;
	while (env[i])
	{
		if (strncmp(env[i], "PATH", 4) == 0)
		{
			break;
		}
		i++;
	}

	return (env[i]);
}

/*char * filter_path(char * command, char *path)
{
	int size_path = strlen(path);
	char * concatenated_path = malloc(5000);
	struct stat buf;
		
	printf("%s, this is the path", path);

	strcpy(concatenated_path, path);

	concatenated_path[size_path++] = "/";

	strcat(concatenated_path, command);

	printf("%s\n\n", concatenated_path);

	stat(concatenated_path, &buf);

	return(concatenated_path);
}*/