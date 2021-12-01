#include "main.h"

void *exe_cd(char **args)
{
	printf("Here goes a CD proc\n");
	printf("%s\n", args[0]);
	return (NULL);
}
void *exe_help(char **args)
{
	printf("Here goes a help proc\n");
	printf("%s\n", args[0]);
	return (NULL);
}
void *exe_exit(char **args)
{
	(void)(args);
	printf("Here goes an Exit proc\n");
	exit(EXIT_SUCCESS);
}