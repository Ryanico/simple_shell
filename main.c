#include "shell.h"
/*
 *My main.c function
 */

int main(void) {
	char function[130];

	while (true) {
		personal_prompt();
		read_function(function, sizeof(function));
		execute_function(function);
	}


	return 0;
}
