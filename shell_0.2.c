#include "shell.h"



int main()
{
    char* command = NULL;
    size_t length = 0;
    ssize_t read;
    

    while (1)
    {
        prompt();

        read = my_getline(&command, &length, stdin);

        if (read == -1)
        {
            break;
        }

        command[strcspn(command, "\n")] = 0;

        execwitharg(command );
    }

    free(command); 
    return 0;
}
