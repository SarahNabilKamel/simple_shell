#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h> 
#include <sys/wait.h>

#define COMMAND_MAX_LINE 1024


int main() 
{
    char* command_line = NULL;
    size_t length = 0;
    ssize_t read;
    pid_t pid;
    while(1) 
    {

        printf("#cisfun$ ");
        fflush(stdout);

        read = getline(&command_line, &length, stdin);

        if(read == -1)
        {
            break;
        }

        command_line[strcspn(line, "\n")] = 0; 

        pid = fork();

        if(pid == -1) 
        {
            perror("fork");
            exit(1);
        } 
        else if(pid == 0) 
        { 

            char* args[] = {strtok(line, " "), NULL};

            execve(args[0], args, NULL);
            perror("execve");
            exit(1);

        }
        else
        {
            wait(NULL);
        }
    }

    return 0;
}