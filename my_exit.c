#include "shell.c"

int is_exit_command(char *command_line)
{
    return strcmp(command_line, "exit") == 0;
}