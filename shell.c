#include "shell.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

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