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

/* void free_args(char **token)
{
	int i = 0;

	printf("%s\n", token[i]);

	while (token[i] != NULL)
	{
		free(token[i]);
		i++;
	}
	free(token);
} */

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

char *filter_path(char **path, char *command)
{
	unsigned int i = 0, j = 0, k = 0;
	char *temp = NULL;

	if(access(command, X_OK) == 0)
		return(command);


	for (i = 0; path[i]; i++)
	{
		j = strlen(path[i]);
		k = strlen(command);

		temp = malloc(sizeof(char) + j + k + 2);
		if (temp == NULL)
			exit(-1);

		strcpy(temp, path[i]);
				
		if (temp[j] != '/')
			strcat(temp, "/");
		strcat(temp, command);
		strcat(temp, "\0");
		if (access(temp, X_OK) == 0)
		{
			return (temp);
		}
		printf("%s\n\n", temp);
		free(temp);
	}
	return (NULL);
}