#include "shell.h"
/**
 * print_environment - prints global environ variable
 *
 * Return: void
 */
void print_environment(void)
{
	int i;

	for (i = 0; environ[i] != NULL; i++)
	{
		printf("%s\n", environ[i]);
	}
}

