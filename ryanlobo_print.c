#include "shell.h"

void ryanlobo_print(const char *function) {
	write(STDOUT_FILENO, function, strlen(function));
}
