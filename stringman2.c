#include "shell.h"
/**
 * my_strlen - length of string
 * @str: Pointer to string
 *
 * Return: returns length of string
 */
size_t my_strlen(const char *str)
{
	const char *s = str;

	while (*s)
	{
		s++;
	}
	return (s - str);
}
/**
 * my_strdup - duplicates a string
 * @str: Pointer to source string
 *
 * Return: pointer copy
 */
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

	return (copy);
}
/**
 * is_whitespace - checks for white space
 * @c: character to check
 *
 * Return: true or false
 */
int is_whitespace(char c)
{
	return (c == ' ' || c == '\t' || c == '\n' ||
	c == '\r' || c == '\f' || c == '\v');
}

