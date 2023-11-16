#include "shell.h"

/**
 * auxhelp_env - Help information for the built in env
 * Return: no return
 */
void auxhelp_env(void)
{
	char *Help = "env: env [option] [name=value] [command [args]]\n\t";

	write(STDOUT_FILENO, Help, strlen(Help));
	Help = "Print the enviroment of the shell.\n";
	write(STDOUT_FILENO, Help, strlen(Help));

}
/**
 * auxhelp_setenv - Help information for the built in setenv
 * Return: no return
 */
void auxhelp_setenv(void)
{

	char *Help = "setenv: setenv (const char *name, const char *value,";

	write(STDOUT_FILENO, Help, strlen(Help));
	Help = "int replace)\n\t";
	write(STDOUT_FILENO, Help, strlen(Help));
	Help = "Add a new definition to the environment\n";
	write(STDOUT_FILENO, Help, strlen(Help));
}
/**
 * auxhelp_unsetenv - Help information for the built in unsetenv
 * Return: no return
 */
void auxhelp_unsetenv(void)
{
	char *Help = "unsetenv: unsetenv (const char *name)\n\t";

	write(STDOUT_FILENO, Help, strlen(Help));
	Help = "Remove an entry completely from the environment\n";
	write(STDOUT_FILENO, Help, strlen(Help));
}


/**
 * auxhelp_general - Entry point for help information for help built in
 * Return: no return
 */
void auxhelp_general(void)
{
	char *Help = "^-^ bash, version 1.0(1)-release\n";

	write(STDOUT_FILENO, Help, strlen(Help));
	Help = "These commands are defined internally.Type 'Help' to see the list";
	write(STDOUT_FILENO, Help, strlen(Help));
	Help = "Type 'Help name' to find out more about the function 'name'.\n\n ";
	write(STDOUT_FILENO, Help, strlen(Help));
	Help = " alias: alias [name=['string']]\n cd: cd [-L|[-P [-e]] [-@]] ";
	write(STDOUT_FILENO, Help, strlen(Help));
	Help = "[dir]\nexit: exit [n]\n  env: env [option] [name=value] [command ";
	write(STDOUT_FILENO, Help, strlen(Help));
	Help = "[args]]\n  setenv: setenv [variable] [value]\n  unsetenv: ";
	write(STDOUT_FILENO, Help, strlen(Help));
	Help = "unsetenv [variable]\n";
	write(STDOUT_FILENO, Help, strlen(Help));
}
/**
 * auxhelp_exit - Help information fot the builint exit
 * Return: no return
 */
void auxhelp_exit(void)
{
	char *Help = "exit: exit [n]\n Exit shell.\n";

	write(STDOUT_FILENO, Help, strlen(Help));
	Help = "Exits the shell with a status of N. If N is ommited, the exit";
	write(STDOUT_FILENO, Help, strlen(Help));
	Help = "statusis that of the last command executed\n";
	write(STDOUT_FILENO, Help, strlen(Help));
}
