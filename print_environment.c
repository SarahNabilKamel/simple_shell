#include "shell.h"

void print_environment()
{
    extern char **environ;

    for (int i = 0; environ[i] != NULL; i++)
    {
        printf("%s\n", environ[i]);
    }
}
