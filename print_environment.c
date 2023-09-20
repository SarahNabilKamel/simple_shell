#include "shell.h"

/**
 * print_environment - Print the global environ variable
 * @envp: Pointer to the environment variable array
 *
 * Return: void
 */
void print_environment(char **envp)
{
    int i = 0;
    char *env_var;

    while (envp[i] != NULL)
    {
        env_var = envp[i];
        write(STDOUT_FILENO, env_var, my_strlen(env_var));
        write(STDOUT_FILENO, "\n", 1);
        i++;
    }
}
