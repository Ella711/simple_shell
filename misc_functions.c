#include "main.h"

/**
 * look_for_path - search the path on the env
 *
 * @tokens: tokenized path
 * @argc: number of args
 * @argv: Arguments
 * @tty: interactive or not
 * Return: char*
 */
char *look_for_path(char **tokens, int argc, char **argv, int tty)
{
	int i = 0;
	

	while (environ[i])
	{
		if (_strncmp(environ[i], "PATH=", 5) == 0)
		{
			return(environ[i]);
		}

		i++;
	}
	error_handling(argc, argv, tokens, tty);

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
		free(tokenized);
		exit(127);
	}
	else
		fprintf(stderr, "%s: not found\n", tokenized[0]);
}

/**
 * _strcmp - Compare two strings
 * @s1: Input string 1
 * @s2: Input string 2
 * Return: Value of the compare
 */
int _strcmp(char *s1, char *s2)
{
	int compare = 0;
	int i = 0;

	while (s1[i] && s2[i])
	{
		if (s1[i] != s2[i])
		{
			compare = s1[i] - s2[i];
			break;
		}
		i++;
	}
	return (compare);
}
