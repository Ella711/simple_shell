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

typedef struct builtin
{
    char *command;
    void *(*command_func)(char **);
} builtin_t;


extern char **env;

/*Duplicates a string*/
char *_strdup(char *str);
/*Tokenizer*/
char **tokenize_line(char *line);
/*Execute*/
int exec_proc(char **args, char **env);
/*Function to pointer*/
void *(*is_built_in(char **args))(char **tokenized);
/*cd command*/
void * exe_cd(char **);
/*help command*/
void * exe_help(char **);
/*exit command*/
void * exe_exit(char **);


/*Look for the PATH*/
char * look_for_path(char **env);
/*Tokenize PATH*/
char **tokenize_path(char *line);
/*filther path*/
char * filter_path(char * command, char *path);

#endif /*MAIN_HEADER*/