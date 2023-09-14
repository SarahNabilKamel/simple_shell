#include "shell.h"

void exec3(char *command_line)
{
        pid_t pid;
        char* token;
        char* command;
        char** args;
        int i;
        
        char* command_line_copy ;
        command_line_copy = strdup(command_line);

        token = strtok(command_line_copy, " ");
        args = malloc((COMMAND_MAX_LENGTH + 1) * sizeof(char*));
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
            char* path_copy = strdup(path);
            char* path_token = strtok(path_copy, ":");

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

            free(path_copy);
        }

        free(args);
        free(command_line_copy);
}