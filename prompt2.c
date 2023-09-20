#include "shell.h"

/**
 * prompt2 - start of line
 * Return: void
 */
void prompt2(void)
{
	char prompt[] = "$ ";
	if (isatty(STDIN_FILENO))
		write(STDOUT_FILENO, prompt, sizeof(prompt) - 1);
	fflush(stdout);
}
