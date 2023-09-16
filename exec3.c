#include "shell.h"
/**
 * tokenize - Tokenizes the command line into arguments
 * @command_line: Pointer to the command line string
 * @args: Array to store the tokenized arguments
 * Return: Number of arguments
 */
int tokenize(char *command_line, char **args)
{
    char *token;
    int i = 0;
    char *command_line_copy = strdup(command_line);

    token = strtok(command_line_copy, " ");
    while (token != NULL)
    {
        args[i++] = token;
        token = strtok(NULL, " ");
    }
    args[i] = NULL;

    free(command_line_copy);
    return i;
}

/**
 * execute_command - Executes the command with the given arguments
 * @command: Command to execute
 * @args: Arguments for the command
 */
void execute_command(char *command, char **args)
{
    pid_t pid;

    if (access(command, X_OK) == 0)
    {
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
        char *path = getenv("PATH");
        char *path_copy = strdup(path);
        char *path_token = strtok(path_copy, ":");

        while (path_token != NULL)
        {
            char *full_path = malloc(strlen(path_token) + strlen(command) + 2);
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
            fprintf(stderr, " ./hsh: 1: %s : not found\n", command);
        }

        free(path_copy);
    }
}

/**
 * exec3 - Executes the command line
 * @command_line: Pointer to the command line argument
 */
void exec3(char *command_line)
{
    char *command;
    char **args;
    int num_args;

    if (command_line == NULL)
        return;

    args = malloc((COMMAND_MAX_LENGTH + 1) * sizeof(char *));
    num_args = tokenize(command_line, args);
    command = args[0];

    execute_command(command, args);

    free(args);
}

