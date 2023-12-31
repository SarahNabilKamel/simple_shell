#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

extern char **environ;

#define COMMAND_MAX_LENGTH 1024

size_t my_strcspn(const char *str, const char *reject);
size_t my_strlen(const char *str);
char *my_strcpy(char *dest, const char *src);
char *my_strcat(char *dest, const char *src);
char *my_strdup(const char *str);
int my_strcmp(const char *str1, const char *str2);
void prompt2(void);
void exec3(char **args, int *status, char *executable);
void print_environment(char **envp);
int is_env_command(char *command_line);
int is_exit_command(char *command_line);
void execute_command(char *command, char **args, int *status);
void find_executable(char *command, char **args,
char *path, int *status, char *prog);
int is_whitespace(char c);

char **f_token(char *command);
void array_free(char **array);
char *get_value(char *key);

#endif

