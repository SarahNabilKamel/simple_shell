#include "shell.h"

/**
 * main - Start point of our simple shell
 * Return: Always 0 (success)
*/
int main(void)
{
	char *command = NULL;
	size_t command_len = 0;

	while (1)
	{
		prompt();
		if (my_getline(&command, &command_len, stdin) == -1)
		{
			break;
		}
		command[strcspn(command, "\n")] = '\0';
		my_exec(command);
	}
	free(command);
	return (0);
}
