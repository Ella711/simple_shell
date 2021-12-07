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
 * look_for_path - looks for PATH
 * Return: PATH
 */

char *look_for_path(char **tokens, int argc, char **argv, int tty)
{
	int i = 0;

	while (environ[i])
	{
		if (strncmp(environ[i], "PATH=", 5) == 0)
		{
			break;
		}
		else
			error_handling(argc, argv, tokens, tty);
		i++;
	}

	return (environ[i]);
}

/**
 * filter_path - concatenates command with each tokened path and checks access
 * @path: tokenized path
 * @command: command
 * Return: NULL if not found
 */

char *filter_path(char **path, char *command)
{
	unsigned int i = 0, j = 0, k = 0, u = 0;
	char *temp = NULL;

	if (access(command, X_OK) == 0)
		return (command);


	for (i = 0; path[i]; i++)
	{
		j = strlen(path[i]);
		k = strlen(command);
		u = j + k + 2;
		temp = malloc(sizeof(char) + u);
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
		/*printf("%s\n\n", temp);*/
		free(temp);
	}
	return (NULL);
}

/**
 * error_handling - handles error depending on mode
 * @argc: argument counter
 * @argv: arguments
 * @tokenized: tokenized line of command
 * @tty: non/interactive mode
 */

void error_handling(int argc, char **argv, char **tokenized, int tty)
{
	if (tty == 0)
	{
		fprintf(stderr, "%s: %d: %s: not found\n", argv[0], argc, tokenized[0]);
		exit(127);
	}
	else
		fprintf(stderr, "%s: not found\n", tokenized[0]);
}
