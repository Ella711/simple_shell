#ifndef MAIN_HEADER
#define MAIN_HEADER

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <fcntl.h>

/**
 * struct builtin - new typedef for struct
 * @command: string with command
 * @command_func: function to execute command
 */

typedef struct builtin
{
char *command;
int (*command_func)(char **args);
} builtin_t;


extern char **environ;

/* handles ctrl_c */
void ctrl_c(int sig);
/*Duplicates a string*/
char *_strdup(char *str);
/*Tokenizer*/
char **tokenize_line(char *line);
/*Execute*/
int exec_proc(char **args, char *path);
/*Function to pointer*/
int (*is_built_in(char **args))(char **tokenized);
/*cd command*/
int exe_cd(char **args);
/*help command*/
int exe_help(char **args);
/*exit command*/
int exe_exit(char **args);
/*print env*/
int exe_env(char **args);


/* READS LINE */
char *read_line(void);
/*Look for the PATH*/
char *look_for_path();
/*Tokenize PATH*/
char **tokenize_path(char *line);
/*filther path*/
char *filter_path(char **path, char *command);
/* check if can be executed */
int check_exec(char **tokens, int argc, char **argv, int tty);
/*free elements*/
void free_elements(char *free1, char **free2);
/* handles errors */
void error_handling(int argc, char **argv, char **tokenized, int tty);

#endif /*MAIN_HEADER*/
