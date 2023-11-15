#include "shell.h"

/**
 * aux_help_ - Help information for the builtin help.
 * Return: no return
 */
void aux_help_(void)
{
	char *Help = "Help: Help [-dms] [pattern ...]\n";

	write(STDOUT_FILENO, Help, _strlen(Help));
	Help = "\tDisplay information about builtin commands.\n ";
	write(STDOUT_FILENO, Help, _strlen(Help));
	Help = "Displays brief summaries of builtin commands.\n";
	write(STDOUT_FILENO, Help, _strlen(Help));
}
/**
 * auxhelp_alias - Help information for the builtin alias.
 * Return: no return
 */
void auxhelp_alias(void)
{
	char *Help = "alias: alias [-p] [name[=value]...]\n";

	write(STDOUT_FILENO, Help, _strlen(Help));
	Help = "\tDefine or display aliases.\n ";
	write(STDOUT_FILENO, Help, _strlen(Help));
}
/**
 * auxhelp_cd - Help information for the builtin alias.
 * Return: no return
 */
void auxhelp_cd(void)
{
	char *Help = "cd: cd [-L|[-P [-e]] [-@]] [dir]\n";

	write(STDOUT_FILENO, Help, _strlen(Help));
	Help = "\tChange the shell working directory.\n ";
	write(STDOUT_FILENO, Help, _strlen(Help));
}
