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
        char* token;
        char* command;
        char** args;
        int i;

        printf(":) ");
        fflush(stdout);

        read = getline(&command_line, &length, stdin);

        if (read == -1)
        {
            break;
        }

        command_line[strcspn(command_line, "\n")] = '\0';

        token = strtok(command_line, " ");
        args = malloc((COMMAND_MAX_LINE + 1) * sizeof(char*));
        i = 0;

        while (token != NULL)
        {
            args[i++] = token;
            token = strtok(NULL, " ");
        }
        
	
        args[i] = NULL;


        command = args[0];
        if (access(command, X_OK) == 0) {

            pid = fork();

            if (pid == -1)
            {
                perror("fork");
                exit(1);
            }
            else if (pid == 0)
            {
                execve(command, args, NULL);
                perror(command);
                exit(1);
            }
            else
            {
                wait(NULL);
            }
        }
        else
        {

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

                    pid = fork();

                    if (pid == -1)
                    {
                        perror("fork");
                        exit(1);
                    }
                    else if (pid == 0)
                    {
                        execve(full_path, args, NULL);
                        perror(command);
                        exit(1);
                    }
                    else
                    {
                        wait(NULL);
                    }

                    free(full_path);
                    break;
                }

                free(full_path);
                path_token = strtok(NULL, ":");
            }

            if (path_token == NULL)
            {

                fprintf(stderr, "%s: command not found\n", command);
            }
        }

        free(args);
    }

    free(command_line);
    return 0;
}
