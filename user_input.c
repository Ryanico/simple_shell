#include "shell.h"

void read_function(char *function, size_t size) {
	if (fgets(function, size, stdin) == NULL) {
		if (feof(stdin)) {
			ryanlobo_print("\n");
			exit(EXIT_SUCCESS);
		} else {
			ryanlobo_print("Error while reading input.\n");
			exit(EXIT_FAILURE);
		}
	}
	function[strcspn(function, "\n")] = '\0'; // Remove newline
}



#include "shell.h"

void read_function(char *function, size_t size) {
	if (fgets(function, size, stdin) == NULL) {
		if (feof(stdin)) {
			ryanlobo_print("\n");
			exit(EXIT_SUCCESS);
		} else {
			ryanlobo_print("Error while reading input.\n");
			exit(EXIT_FAILURE);
		}
	}
	function[strcspn(function, "\n")] = '\0'; // Remove newline
}
