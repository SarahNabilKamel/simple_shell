#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>

#define PROMPT ":) "

int main()
{
    char* command = NULL;
    size_t bufsize = 0;

    while(1) 
    {
    
    printf(PROMPT);
    

    if(getline(&command, &bufsize, stdin) == -1) 
    {
    break;
    }
    
    
    command[strlen(command)-1] = '\0';
    
    
    char *path = getenv("PATH");
    char *paths[10];
    char full_path[1024];
    int i = 0;
    
    paths[0] = strtok(path, ":");
    while(paths[i] != NULL) 
    {
    i++;
    paths[i] = strtok(NULL, ":"); 
    }
    
    for(int j = 0; j <= i; j++) 
    {
    strcpy(full_path, paths[j]);
    strcat(full_path, "/");
    strcat(full_path, command);
    
    if(access(full_path, X_OK) == 0)
    {
        break;
    }
    
    }
    
    if(j > i) 
    {
    printf("Command not found: %s\n", command);
    continue;
    }
    
    
    pid_t pid = fork();
    if(pid == 0) 
    {
    execl(full_path, command, NULL);
    exit(1); 
    } else 
    {
    wait(NULL);
    }
    
}

if(command)  
{
    free(command);
}

return 0;
}