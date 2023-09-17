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
		printf("%s\n", env_var);
		i++;
	}
}
