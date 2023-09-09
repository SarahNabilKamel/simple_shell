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

    while (1)
    {
        printf("#cisfun$ ");
        fflush(stdout);

        read = getline(&command_line, &length, stdin);

        if (read == -1)
        {
            break;
        }

        command_line[strcspn(command_line, "\n")] = 0;

        pid = fork();

        if (pid == -1)
        {
            perror("fork");
            exit(1);
        }
        else if (pid == 0)
        {
            // Tokenize the command_line string
            char* token = strtok(command_line, " ");
            char** args = malloc((COMMAND_MAX_LINE + 1) * sizeof(char*));
            int i = 0;

            while (token != NULL)
            {
                args[i++] = token;
                token = strtok(NULL, " ");
            }

            args[i] = NULL; // Set the last element to NULL

            execvp(args[0], args);
            perror("execvp");
            exit(1);
        }
        else
        {
            wait(NULL);
        }
    }

    free(command_line); // Free dynamically allocated memory
    return 0;
}