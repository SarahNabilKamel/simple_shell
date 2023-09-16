#include "shell.h"
/**
 * execwitharg - our execute commandline with argument
 * @command: pointer to command line argument
 * Return: void
 */
void execwitharg( char *command )
{       
        pid_t pid;
        pid = fork();

        if (pid == -1)
        {
            perror("fork");
            exit(1);
        }
        else if (pid == 0)
        {
            
            char* token = strtok(command, " ");
            char** args = malloc((COMMAND_MAX_LENGTH + 1) * sizeof(char*));
            int i = 0;

            while (token != NULL)
            {
                args[i++] = token;
                token = strtok(NULL, " ");
            }

            args[i] = NULL; 

            execve(args[0], args, NULL);
            perror("./shell");
            exit(1);
        }
        else
        {
            wait(NULL);
        }
}