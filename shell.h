#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

#define COMMAND_MAX_LENGTH 1024

void prompt();
ssize_t my_getline(char **lineptr, size_t *n, FILE *stream);
void my_exec( char *command );
void execwitharg( char *command );
void prompt2();
void exec3(char *command);


#endif