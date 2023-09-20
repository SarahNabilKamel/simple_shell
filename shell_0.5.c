#include "shell.h"

/**
 * main - Entry point of the simple shell program
 * @argc: Number of command-line arguments
 * @argv: Array of command-line argument strings
 * @envp: Array of environment variable strings
 *
 * Return: Always 0
 */
int main(
    int argc __attribute__((unused)),
    char *argv[] __attribute__((unused)),
    char *envp[]
)
{
    char *command_line;
    size_t length = 0;
    ssize_t read;

    command_line = NULL;
    
    while (1)
    {
        prompt2();

        read = getline(&command_line, &length, stdin);

        if (read == -1)
        {
	    free(command_line);
            break;
        }

        command_line[read - 1] = '\0';

        while (*command_line && is_whitespace(*command_line))
        {
            command_line++;
        }

        if (*command_line != '\0')
        {
            if (is_exit_command(command_line))
            {
                break;
            }
            else if (is_env_command(command_line))
            {
                print_environment(envp);
            }
            else
            {
                exec3(command_line);
            }
        }
    }

    free(command_line);
    return (0);
}
