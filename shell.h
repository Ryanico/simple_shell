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
void free_sep_lists(sep_lists **Head);
line_lists *adds_line_node_end(line_lists **Head, char *Line);
void frees_line_list(line_lists **Head);
void _memscpy(void *Newptrs, const void *ptrs, unsigned int Size);
void *_reallocs(void *ptrs, unsigned int old_Size, unsigned int new_Size);
char **_reallocsdp(char **ptrs, unsigned int old_Size, unsigned int new_Size);






#endif /* SHELL_H */
