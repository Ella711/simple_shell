#include "main.h"

int main(int argc, char **argv, char **env)
{
	char *line = NULL, *path = NULL;
	char **tokenized = NULL, **token_path = NULL;

	char *path_dir = NULL;
	int (*func_builtin)(char **);

	int tty = 1, vuelta = 0, status;

	(void)(argv);
	(void)(argc);
	(void)(env);

	signal(SIGINT, ctrl_d);

	if (isatty(STDIN_FILENO) == 0)
		tty = 0;

	do
	{
		if (tty == 1) /*Interactive Mode*/
			write(STDOUT_FILENO, "($H3LL) - ", 10);

		fflush(stdin);
		/* READ */
		line = read_line();
		/*Split or tokenize the input*/
		tokenized = tokenize_line(line);
		/*Cheks if it is built in or isn't*/
		if (tokenized[0])
			func_builtin = is_built_in(tokenized);
		else
			continue;
		/*Execute*/
		if (func_builtin == NULL)
		{

			if (access(tokenized[0], X_OK) != 0)
			{
				path_dir = look_for_path(env);
				if (vuelta == 0)
					token_path = tokenize_path(path_dir);
			}
			path = filter_path(token_path, tokenized[0]);
			if (path != NULL)
			{
				status = exec_proc(tokenized, env, path);
			}
			else
				perror("Command Not Found");
		}
		else
		{
			func_builtin(tokenized);
		}
		vuelta++;
		

	} while (status);

	free(line);
	return (0);
}

char *read_line(void)
{
	char *line = NULL;
	size_t len = 0;

	
	if (getline(&line, &len, stdin) == -1)
	{
		free(line);
		exit (0);
	}
	return (line);
}

void ctrl_d(int sig)
{
	(void)sig;
	exit(EXIT_SUCCESS);
}