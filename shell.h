#ifndef SHELL_H
#define SHELL_H
/*
 *These are my header files
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <stdbool.h>
#include <stddef.h>

/**
 * struct data - struct that contains all relevant data on runtime
 * @av: argument vector
 * @input: command line written by the user
 * @args: tokens of the command line
 * @status: last status of the shell
 * @counter: lines counter
 * @_environ: environment variable
 * @pid: process ID of the shell
 */
typedef struct data
{
	char **av;
	char *input;
	char **args;
	int status;
	int counter;
	char **_environ;
	char *pid;
} shell_data;


/**
 * struct sep_list_s - single linked list
 * @separator: ; | &
 * @next: next node
 * Description: single linked list to store separators
 */
typedef struct sep_list_s
{
	char separator;
	struct sep_list_s *next;
} sep_lists;


/**
 * struct r_var_list - single linked list
 * @len_var: length of the variable
 * @vals: value of the variable
 * @len_val: length of the value
 * @next: next node
 * Description: single linked list to store variables
 */
typedef struct r_var_list
{
	int len_var;
	char *vals;
	int len_val;
	struct r_var_list *next;
} r_vars;


/**
 * struct line_list_s - single linked list
 * @line: command line
 * @next: next node
 * Description: single linked list to store command lines
 */
typedef struct line_list_s
{
	char *line;
	struct line_list_s *next;
} line_lists;



/*
 *These are my prototypes
 */
void personal_prompt(void);
void ryanlobo_print(const char *function);
void read_function(char *function, size_t size);
void execute_function(const char *function);
char *strconct_cd(shell_data *datsh, char *message, char *err, char *ver_stng);
char *errorget_cd(shell_data *datsh);
char *errornot_found(shell_data *datsh);
char *errorexit_shell(shell_data *datsh);
char *err_env(shell_data *datsh);
char *errorpath_111(shell_data *datsh);
void auxhelp_env(void);
void auxhelp_setenv(void);
void auxhelp_unsetenv(void);
void auxhelp_general(void);
void auxhelp_exit(void);
void aux_help_(void);
void auxhelp_alias(void);
void auxhelp_cd(void);
r_vars *adds_rvar_node(r_vars **Head, int lvars, char *vals, int lvals);
void frees_rvar_list(r_vars **Head);
sep_lists *adds_sep_node_end(sep_lists **Head, char Sep);
void free_sep_list(sep_lists **Head);
line_lists *adds_line_node_end(line_lists **Head, char *Line);
void frees_line_list(line_lists **Head);
void _memscpy(void *Newptrs, const void *ptrs, unsigned int Size);
void *_reallocs(void *ptrs, unsigned int old_Size, unsigned int new_Size);
char **_reallocsdp(char **ptrs, unsigned int old_Size, unsigned int new_Size);






#endif /* SHELL_H */
