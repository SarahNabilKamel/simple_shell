#include "shell.h"
/**
 * main - start point our simple shell
 *
 * Return: Always 0
 */
#include "shell.h"

int main(int argc, char *argv[], char *envp[])
{
    char *command_line = NULL;
    size_t length = 0;
    ssize_t read;

    while (1)
    {
        prompt2();

        read = my_getline(&command_line, &length, stdin);

        if (read == -1)
        {
            break;
        }

        command_line[strcspn(command_line, "\n")] = '\0';

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

    free(command_line);
    return 0;
}