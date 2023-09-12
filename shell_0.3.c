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
        printf(":) ");
        fflush(stdout);

        read = getline(&command_line, &length, stdin);

        if (read == -1)
        {
            break;
        }

        command_line[strcspn(command_line, "\n")] = '\0';

        pid = fork();

        if (pid == -1)
        {
            perror("fork");
            exit(1);
        }
        else if (pid == 0)
        {
        

            char* token = strtok(command_line, " ");
            char* command = token;

        
            char* path = getenv("PATH");
            char* path_token = strtok(path, ":");

            while (path_token != NULL)
            {
                char* full_path = malloc(strlen(path_token) + strlen(command) + 2);
                strcpy(full_path, path_token);
                strcat(full_path, "/");
                strcat(full_path, command);

                if (access(full_path, X_OK) == 0)
                {
                
                    char** args = malloc((COMMAND_MAX_LINE + 1) * sizeof(char*));
                    int i = 0;
                    args[i++] = command;

                    while (token != NULL)
                    {
                        args[i++] = token;
                        token = strtok(NULL, " ");
                    }

                    args[i] = NULL;

                    execve(full_path, args, NULL);
                    perror(command);
                    exit(1);
                }

                free(full_path);
                path_token = strtok(NULL, ":");
            }

            
            fprintf(stderr, "%s: command not found\n", command);
            exit(1);
        }
        else
        {
            
            wait(NULL);
        }
    }

    free(command_line);
    return 0;
}