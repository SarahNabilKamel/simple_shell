#include "shell.h"
/**
 * is_exit_command - checks if command line is exit command
 * @command_line: pointer to command line
 * Return: boolean
 */
int is_exit_command(char *command_line)
{
    return strcmp(command_line, "exit") == 0;
}