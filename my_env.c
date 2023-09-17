#include "shell.h"

/**
 * is_env_command - Check if the command line is an "env" command
 * @command_line: Pointer to the command line
 * * Return: 1 if it is an "env" command, 0 otherwise
 */
int is_env_command(char *command_line)
{
	return (strcmp(command_line, "env") == 0);
}
