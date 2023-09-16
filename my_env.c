#include "shell.h"
/**
 * is_env_command - checks if command line is env
 * @command_line: pointer to command line
 * Return: Always 0, positive value or negative value
 */
int is_env_command(char *command_line)
{
	return (strcmp(command_line, "env") == 0);
}

