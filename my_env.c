#include "shell.h"

int is_env_command(char *command_line)
{
    return strcmp(command_line, "env") == 0;
}