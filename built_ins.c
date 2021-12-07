#include "main.h"

/**
 * exe_cd - built in function for cd
 * @args: arguments
 * Return: 1
 */

int exe_cd(char **args)
{
	if (args[1] == NULL)
		perror("Expected path to cd");
	else
	{
		if (chdir(args[1]) != 0)
			perror("Could not change directory");
	}
	printf("%s\n", args[1]);
	return (1);
}

/**
 * exe_help - built in function for help
 * @args: arguments
 * Return: 1
 */

int exe_help(char **args)
{
	printf("Here goes a help proc\n");
	printf("%s\n", args[0]);
	return (1);
}

/**
 * exe_exit - built in function for exit
 * @args: arguments
 * Return: 1
 */

int exe_exit(char **args)
{
	(void)(args);
	printf("Here goes an Exit proc\n");
	return (EXIT_SUCCESS);
}

/**
 * exe_env - built in function for env
 * @args: arguments
 * Return: 1
 */

int exe_env(char **args)
{
	int i = 0;
	(void)(args);

	while (environ[i])
	{
		printf("%s\n", environ[i]);
		i++;
	}
	return (1);
}
