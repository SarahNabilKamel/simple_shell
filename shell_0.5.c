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
	char *argv[],
	char *envp[])
{
	char **args;
	char *command_line;
	int status = 0;
	size_t length = 0;
	ssize_t read;

	while (1)
	{
		command_line = NULL;
		prompt2();

		read = getline(&command_line, &length, stdin);
		if (read == -1)
		{
			free(command_line);
			exit(status);
		}
		command_line[read - 1] = '\0';
		args = f_token(command_line);
		if (args)
		{
			if (is_exit_command(args[0]))
			{
				array_free(args);
				free(command_line);
				exit(status);
			}
			else if (is_env_command(args[0]))
				print_environment(envp);
			else
				exec3(args, &status, argv[0]);
		}
		free(command_line);
	}

	return (0);
}

