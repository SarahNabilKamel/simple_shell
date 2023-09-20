#include "shell.h"


size_t my_strcspn(const char *str, const char *reject)
{
    const char *s1, *s2;
    size_t count = 0;

    for (s1 = str; *s1 != '\0'; s1++)
    {
        for (s2 = reject; *s2 != '\0'; s2++)
        {
            if (*s1 == *s2)
            {
                return count;
            }
        }
        count++;
    }

    return count;
}


char *my_strcpy(char *dest, const char *src)
{
    char *d = dest;
    const char *s = src;

    while ((*d++ = *s++))
    {
        /* Copy character from source to destination */
    }

    return dest;
}

char *my_strcat(char *dest, const char *src)
{
    char *d = dest;
    const char *s = src;

    while (*d)
    {
        d++;
    }

    while ((*d++ = *s++))
    {
        /* Copy character from source to destination */
    }

    return dest;
}

int my_strcmp(const char *str1, const char *str2)
{
    while (*str1 && (*str1 == *str2))
    {
        str1++;
        str2++;
    }

    return *(unsigned char *)str1 - *(unsigned char *)str2;
}





