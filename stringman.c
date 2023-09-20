#include "shell.h"
/**
 * my_strcspn - returns the index of the first character found
 * @str: Pointer to string
 * @reject: Pointer to the reject char
 * Return: count of characters checked so far or entire
 * length of string if not match found
 */
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
				return (count);
			}
		}
		count++;
	}

	return (count);
}
/**
 * my_strcpy - copys a string from source to destination
 * @dest: Pointer to destination string
 * @src: Pointer to source string
 * Return: pointer to destination string
 */
char *my_strcpy(char *dest, const char *src)
{
	char *d = dest;

	const char *s = src;

	while ((*d++ = *s++))
	{
		/* Copy character from source to destination */
	}

	return (dest);
}
/**
 * my_strcat - concatenates strings
 * @dest: Pointer to destination string
 * @src: Pointer to source string
 * Return: pointer to destination string
 */
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

	return (dest);
}
/**
 * my_strcmp - compares two strings
 * @str1: Pointer to destination string
 * @str2: Pointer to source string
 * Return: 0 if exactly same string or non zero number
 */
int my_strcmp(const char *str1, const char *str2)
{
	while (*str1 && (*str1 == *str2))
	{
		str1++;
		str2++;
	}

	return (*(unsigned char *)str1 - *(unsigned char *)str2);
}

