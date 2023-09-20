#include "shell.h"

/**
 * execute_command - Execute the command
 * @command: Command to be executed
 * @args: Arguments for the command
 *
 * Return: void
 */
void execute_command(char *command, char **args)
{
	pid_t pid = fork();

	if (pid == -1)
	{
		perror("fork");
		exit(1);
	}
	else if (pid == 0)
	{
		execve(command, args, NULL);
		perror(command);
		exit(1);
	}
	else
	{
		wait(NULL);
	}
}

/**
 * find_executable - Find the executable in the provided path
 * @command: Command to be executed
 * @args: Arguments for the command
 * @path: Path variable
 *
 * Return: void
 */
void find_executable(char *command, char **args, char *path)
{
	char *path_token, *full_path;

	path_token = strtok(path, ":");
	while (path_token != NULL)
	{
		full_path = malloc(my_strlen(path_token) + my_strlen(command) + 2);
		my_strcpy(full_path, path_token);
		my_strcat(full_path, "/");
		my_strcat(full_path, command);
		if (access(full_path, X_OK) == 0)
		{
			execute_command(full_path, args);
			free(full_path);
			return;
		}
		free(full_path);
		path_token = strtok(NULL, ":");
	}
	write(STDERR_FILENO, " ./hsh: 1: ", my_strlen(" ./hsh: 1: "));
    write(STDERR_FILENO, command, my_strlen(command));
    write(STDERR_FILENO, " : not found\n", my_strlen(" : not found\n"));
}

/**
 * exec3 - Execute the command
 * @command_line: Pointer to the command line argument
 *
 * Return: void
 */
void exec3(char *command_line)
{
	int i;
	char *token, *command, **args, *cmd_copy, *path, *path_copy;

	cmd_copy = my_strdup(command_line);

	token = strtok(cmd_copy, " ");
	args = malloc((COMMAND_MAX_LENGTH + 1) * sizeof(char *));
	i = 0;

	while (token != NULL)
	{
		args[i++] = token;
		token = strtok(NULL, " ");
	}
	args[i] = NULL;
	command = args[0];
	if (access(command, X_OK) == 0)
	{
		execute_command(command, args);
	}
	else
	{
		path = "/usr/local/bin:/usr/bin:/bin"; 
		path_copy = my_strdup(path);
		find_executable(command, args, path_copy);
		free(path_copy);
	}
	free(args);
	free(cmd_copy);
}
