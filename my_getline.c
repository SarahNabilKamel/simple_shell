#include "shell.h"

/**
 * my_getline - our getline commant
 *@lineptr: pointer to begining of line
 *@n: pointer to size of buffer
 *@stream: pointer to FILE stream
 * Return: -1 on error & number of characters when succes
 */

ssize_t my_getline(char **lineptr, size_t *n, FILE *stream)
{
    char *newptr;
    int c;
    size_t i;
    i = 0;
    
    if (lineptr == NULL || n == NULL || stream == NULL) 
    {
        return -1;
    }


    if (*lineptr == NULL || *n == 0) 
    {
        *n = 128;  
        *lineptr = (char *)malloc(*n);
        if (*lineptr == NULL) {
            return -1;  
        }
    }

    
    
    
    while ((c = fgetc(stream)) != EOF) 
    {
        
        if (i >= *n - 1)
        {
            *n *= 2;
            
            newptr = (char *)realloc(*lineptr, *n);
            if (newptr == NULL) 
            {
                return -1;  
            }
            *lineptr = newptr;
        }

        (*lineptr)[i++] = c;

        if (c == '\n') {
            break;  
        }
    }

    (*lineptr)[i] = '\0';  

    if (i == 0 && c == EOF) 
    {
        return -1;  
    }

    return i;  
}
