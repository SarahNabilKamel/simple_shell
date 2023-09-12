#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

#define COMMAND_MAX_LENGTH 1024

int main()
{
    char *command = NULL;
    size_t command_length = 0;
    pid_t pid;
    int status;

    while (1)
    {
        printf("#cisfun$ ");
        fflush(stdout);

        if (getline(&command, &command_length, stdin) == -1)
        {
            break;
        }

        
        command[strcspn(command, "\n")] = '\0';

        pid = fork();

        if (pid == -1)
        {
            perror("fork");
            exit(1);
        }
        else if (pid == 0)
        {
        
            char *args[] = {command, NULL};

            
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

    free(command);

    return 0;
}