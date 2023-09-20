#include "shell.h"

/**
 * is_exit_command - Check if the command line is an "exit" command
 * @command_line: Pointer to the command line
 * * Return: 1 if it is an "exit" command, 0 otherwise
 */
int is_exit_command(char *command_line)
{
	return (my_strcmp(command_line, "exit") == 0);
}
