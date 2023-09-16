#include "shell.h"
/**
 * is_env_command - checks if command line is env command
 * @command_line: pointer to command line
 * Return: boolean
 */
int is_env_command(char *command_line)
{
    return strcmp(command_line, "env") == 0;
}
