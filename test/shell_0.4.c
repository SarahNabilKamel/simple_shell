#include "shell.h"
/**
 * main - start point our simple shell
 * Return: Always 0
 */
int main(void)
{
	char *command_line = NULL;
	size_t length = 0;
	ssize_t read;

	while (1)
	{
		prompt2();

		read = getline(&command_line, &length, stdin);
		if (read == -1)
		{
			break;
		}

		command_line[my_strcspn(command_line, "\n")] = '\0';
		if (is_exit_command(command_line))
		{
			break;
		}
		exec3(command_line);
	}

	free(command_line);
	return (0);
}
