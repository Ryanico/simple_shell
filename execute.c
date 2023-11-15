 #include "shell.h"

void execute_function(const char *function) {
	pid_t child_pid = fork(); //create a child process

	if (child_pid == -1) {
		perror("fork");
		exit(EXIT_FAILURE);
	} else if (child_pid == 0) {
		// Child process
		execve(function, function, (char *)NULL);
		perror("execve");
		exit(EXIT_FAILURE);
	} else {
		// Parent process
		wait(NULL);
	}
}


#include "shell.h"



void execute_function(const char *function) {
	pid_t child_pid = fork();

	if (child_pid == -1) {
		ryanlobo_print("Error forking process.\n");
		exit(EXIT_FAILURE);
	} else if (child_pid == 0) {
		// Child process

		// Parse the function and its arguments
		char *arg[130]; // Maximum 130 arguments (adjust as needed)
		int args_count = 0;

		char *token = strtok((char *)function, " ");
		while (token != NULL) {
			arg[args_count++] = token;
			token = strtok(NULL, " ");
		}
		arg[args_count] = NULL; // Null-terminate the arguments array

		// Execute the function
		execve(arg[0], arg);

		// If execve fails, print an error message
		ryanlobo_print("Error executing function.\n");
		exit(EXIT_FAILURE);
	} else {
		// Parent process
		wait(NULL);
	}
}
