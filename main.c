#include "main.h"

int main(int argc, char **argv, char **env)
{
	char *entry_info = NULL, *path = NULL;
	char **tokenized = NULL, **token_path = NULL;
	
	char *path_dir = NULL;
	void *(*func_builtin)(char **);

	int fd_read, tty = 1, vuelta = 0;
	size_t len = 0;

	(void)(argv);
	(void)(argc);
	(void)(env);

	if (isatty(STDIN_FILENO) == 0)
		tty = 0;

	do
	{
		if (tty == 1) /*Interactive Mode*/
			write(STDOUT_FILENO, "($H3LL) - ", 10);

		fflush(stdin);
		/* READ */
		fd_read = getline(&entry_info, &len, stdin);
		if (fd_read == -1)
			return (-1);
		/*Split or tokenize the input*/
		tokenized = tokenize_line(entry_info);
		/*Cheks if it is built in or isn't*/
		func_builtin = is_built_in(tokenized);
		/*Execute*/
		if (func_builtin == NULL)
		{
			path_dir = look_for_path(env);
			if (vuelta == 0)
				token_path = tokenize_path(path_dir);
			free(path_dir);
			path = filter_path(token_path, tokenized[0]);
			exec_proc(tokenized, env, path);
		}
		else
			func_builtin(tokenized);
	vuelta++;
	} while (1);

	free(token_path);
	free(entry_info);
	return (0);
}