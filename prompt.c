#include "shell.h"
/**
 * prompt - start of line
 * Return: void
 */
void prompt(void)
{
	char prompt[] = "#cisfun$ ";
    write(STDOUT_FILENO, prompt, sizeof(prompt) - 1);
	fflush(stdout);
}
