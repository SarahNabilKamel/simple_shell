#include "shell.h"
/**
 * main - start point our simple shell
 *
 * Return: Always 0
 */

int main()
{
    char *command = NULL;
    size_t command_length = 0;
    
    

    while (1)
    {
        prompt();

        if (my_getline(&command, &command_length, stdin) == -1)
        {
            break;
        }

        
        command[strcspn(command, "\n")] = '\0';
        
    
        my_exec( command );

        
    }

    free(command);

    return 0;
}