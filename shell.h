#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>
#include "sys/types.h"
#include "dirent.h"

#define BUFFER_S 1024

typedef struct list_s
{
	char *str;
	struct list_s *next;
} list_t;

typedef struct sh_info
{
	char **av;
	char **env;
	int env_num;
	list_t *environ;
	char **args;
	/*char *arg;*/
	int interact;
	char *path;
	int node_len;
	int count;
} hsh;

#define INIT {NULL, NULL, 0, NULL, NULL, 0, NULL, 0, 0}

extern char **environ;

typedef struct built
{
	char *str;
	int (*f)(hsh *);
} builtins;

/* main.c */
void prompt(void);

/** function for exec.c */
char **parser(char *buffer);
int executor(hsh *, char **);
void process(hsh *);
char *path_tok(hsh *);

/* functions in environ.c */
void create_environ(hsh *);

/* functions in linked_nodes.c */
list_t *add_node_begin(list_t **head, const char *str);
list_t *add_node_end(list_t **head, const char *str);

/** functon in get_line.c */
ssize_t _getline(char **lineptr, size_t *n, int);
int ch(char *line, size_t size, ssize_t read_size, char **lineptr, size_t *n);

/** functions in get_env.c */
char *_getenv(char *path, char **);
char **_env(hsh *info);

/** functions in utility.c */
int my_strcmp(const char *s1, const char *s2);
char *my_strdup(const char *str);
char *my_strcpy(char *dest, const char *src);
char *my_strcat(char *dest, const char *src);
size_t my_strlen(const char *str);

/** function in frees.c */
void free_args(char **);
void free_list(list_t *head);
void sh_free(hsh *info, int x);

/** function in strtok.c */
char *sstrtok(char *str, char *delim);
void _sputchar(char c);
void print_str(char *str, int i);

/** function in for_builtins.c */
int builtin(hsh *info);

/** function in builtins.c */
int print_env(hsh *);
int exit_fun(hsh *);

/** function in errno_print.c */
void print_err(hsh *info);
void print_cmd_err(hsh *);
void err_putchar(char c);
char *_itoa(int num);
void reverse(char str[], int length);

#endif

