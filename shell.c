#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

#define MAX_COMMAND_LENGTH 1024

int main()
{
    char command[MAX_COMMAND_LENGTH];
    pid_t pid;
    while (true)
    {
        printf("#cisfun$ ");
        fflush(stdout);

        if (fgets(command, MAX_COMMAND_LENGTH, stdin) == NULL)
        {
            break;
        }

        command[strcspn(command, "\n")] = '\0';

        pid = fork();
        if (pid == -1)
        {
            perror("./shell: Error in fork");
            exit(1);
        }
        else if (pid == 0)
        {
            if (execlp(command, command, NULL) == -1)
            {
                perror("./shell: No such file or directory");
                exit(1);
            }
        }
        else
        {
            wait(NULL);
        }
    }

    return 0;
}