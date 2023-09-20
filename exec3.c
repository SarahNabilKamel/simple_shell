#include "shell.h"

/**
 * execute_command - Execute the command
 * @command: Command to be executed
 * @args: Arguments for the command
 * @status: status
 * Return: void
 */
void execute_command(char *command, char **args, int *status)
{
	pid_t pid = fork();

	if (pid == -1)
	{
		perror("fork");
		exit(1);
	}
	else if (pid == 0)
		execve(command, args, environ);
	else
	{
		waitpid(pid, status, 0);
		if (WIFEXITED(*status)) {
			*status = WEXITSTATUS(*status);
		}
	}
}

/**
 * find_executable - Find the executable in the provided path
 * @command: Command to be executed
 * @args: Arguments for the command
 * @path: Path variable
 * @status: status
 * @prog: name of the program
 * Return: void
 */
void find_executable(char *command, char **args, char *path, int *status, char *prog)
{
	char *path_token, *full_path;

	if (path && *path)
	{
		path_token = strtok(path, ":");
		while (path_token != NULL)
		{
			full_path = malloc(my_strlen(path_token) + my_strlen(command) + 2);
			my_strcpy(full_path, path_token);
			my_strcat(full_path, "/");
			my_strcat(full_path, command);
			if (access(full_path, F_OK) == 0)
			{
				execute_command(full_path, args, status);
				free(full_path);
				return;
			}
			free(full_path);
			path_token = strtok(NULL, ":");
		}
	}
	write(STDERR_FILENO, prog, my_strlen(prog));
	write(STDERR_FILENO, ": 1: ", my_strlen(": 1: "));
    write(STDERR_FILENO, command, my_strlen(command));
    write(STDERR_FILENO, ": not found\n", my_strlen(": not found\n"));
	*status = 127;
}

/**
 * exec3 - Execute the command
 * @command_line: double Pointer to the argument
 * @status: status
 * @executable: program name
 * Return: void
 */
void exec3(char **args, int *status, char *executable)
{
	char *path;

	if (access(args[0], F_OK) == 0)
	{
		execute_command(args[0], args, status);
	}
	else
	{
		path = get_value("PATH");
		find_executable(args[0], args, path, status, executable);
		free(path);
	}
	array_free(args);
}
