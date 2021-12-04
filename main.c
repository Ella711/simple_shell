#include "main.h"

int main(int argc, char **argv, char **env)
{
	char *line = NULL, *path = NULL;
	char **tokenized = NULL, **token_path = NULL;

	char *path_dir = NULL;
	int (*func_builtin)(char **);

	int tty = 1, vuelta = 0, status = 1;

	(void)(argv);
	(void)(argc);
	(void)(env);

	signal(SIGINT, ctrl_d);

	if (isatty(STDIN_FILENO) == 0)
		tty = 0;

	do
	{
		if (tty == 1) /*Interactive Mode*/
			write(STDOUT_FILENO, "($H3LL) -> ", 11);

		fflush(stdin);
		/* READ */
		line = read_line();
		/*Split or tokenize the input*/
		tokenized = tokenize_line(line);
		/*Cheks if it is built in or isn't*/
		if (tokenized[0])
			func_builtin = is_built_in(tokenized);
		else
		{
			free(tokenized);
			free(line);
			continue;
		}
		/*Execute*/
		if (func_builtin == NULL)
		{

			if (access(tokenized[0], X_OK) != 0)
			{
				path_dir = strdup(look_for_path());
				token_path = tokenize_path(path_dir);
				free(path_dir);
				path = filter_path(token_path, tokenized[0]);
				if (path != NULL)
				{
					status = exec_proc(tokenized, path);
					free(path);
				}
				else
					perror("Command Not Found");
				free(token_path);
			}
			else
			{
				status = exec_proc(tokenized, tokenized[0]);
			}
		}
		else
		{
			status = func_builtin(tokenized);
		}
		vuelta++;

		free(tokenized);
		free(line);
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

void ctrl_d(int sig)
{
	(void)sig;
	exit(EXIT_SUCCESS);
}