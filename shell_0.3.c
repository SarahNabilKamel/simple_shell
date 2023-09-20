#include "shell.h"

/**
 * main - Entry point of the simple shell program
 *
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

		exec3(command_line);
	}

	free(command_line);
	return (0);
}
