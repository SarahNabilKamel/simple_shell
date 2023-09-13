#include "shell.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

void my_exec( char *command )
{
        int status;
        pid_t pid;
        pid = fork();

        if (pid == -1)
        {
            perror("fork");
            exit(1);
        }
        else if (pid == 0)
        {
            
            
            char **args = malloc(sizeof(char *) * 2);
            args[0] = command;
            args[1] = NULL;

            
            if (execve(command, args, NULL) == -1)
            {
                perror("./shell");
                exit(1);
            }
        }
        else
        {
        
            if (waitpid(pid, &status, 0) == -1)
            {
                perror("waitpid");
                exit(1);
            }
        }
}