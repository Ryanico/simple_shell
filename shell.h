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




#endif /* SHELL_H */
