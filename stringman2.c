#include "shell.h"

size_t my_strlen(const char *str)
{
    const char *s = str;
    while (*s)
    {
        s++;
    }
    return s - str;
}

char *my_strdup(const char *str)
{
    size_t len = my_strlen(str) + 1;
    char *copy = malloc(len);

    if (copy != NULL)
    {
        char *p = copy;
        while (*str)
        {
            *p++ = *str++;
        }
        *p = '\0';
    }

    return copy;
}

int is_whitespace(char c)
{
    return c == ' ' || c == '\t' || c == '\n' || c == '\r' || c == '\f' || c == '\v';
}
