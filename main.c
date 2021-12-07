#include "main.h"

int main(int argc, char **argv, char **env)
{
	char *line = NULL, **tokenized = NULL;
	int (*func_builtin)(char **);
	int tty = 1, status = 1;
	/* (void)(argv), (void)(argc),  */(void)(env);

	signal(SIGINT, ctrl_c);

	if (isatty(STDIN_FILENO) == 0)
		tty = 0;

	do
	{
		if (tty == 1) /*Interactive Mode*/
			write(STDOUT_FILENO, "($H3LL) -> ", 11);

		fflush(stdin);
		/* READ */
		line = read_line();
		/*TOKEN INPUT*/
		tokenized = tokenize_line(line);
		/*Checks Built-in or Non Built-In*/
		if (tokenized[0])
			func_builtin = is_built_in(tokenized);
		else
		{
			free_elements(line, tokenized);
			continue;
		}
		/*Execute*/
		if (func_builtin == NULL)
			status = check_exec(tokenized, argc, argv, tty);
		else
			status = func_builtin(tokenized);
		free_elements(line, tokenized);
	} while (status);
	return (0);
}

char *read_line(void)
{
	char *line = NULL;
	size_t len = 0;

	if (getline(&line, &len, stdin) == -1)
	{
		if (feof(stdin))
		{
			free(line);
			exit(EXIT_SUCCESS);
		}
		else
		{
			perror("readline");
			exit(EXIT_FAILURE);
		}
	}
	return (line);
}

void ctrl_c(int sig)
{
	(void)sig;
	putchar('\n');
	write(STDOUT_FILENO, "($H3LL) -> ", 11);
}

void free_elements(char *free1, char **free2)
{
	free(free1);
	free(free2);
}
