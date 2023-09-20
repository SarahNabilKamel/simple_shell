#include "shell.h"

char **f_token(char *command_line)
{
	int i = 0;
	char **args;
	char *token, *cmd_copy;

	cmd_copy = my_strdup(command_line);
	token = strtok(cmd_copy, " \t\n");
	if (!token)
	{
		free(cmd_copy);
		return (NULL);
	}
	args = malloc((COMMAND_MAX_LENGTH + 1) * sizeof(char *));

	while (token != NULL)
	{
		args[i++] = my_strdup(token);
		token = strtok(NULL, " \t\n");
	}
	args[i] = NULL;
	free(cmd_copy);
	return args;
}

void array_free(char **array)
{
	int i = 0;

	while (array[i])
		free(array[i++]);
	free(array);
}

char *get_value(char *key)
{
	int i = 0;
	char *res, *holder, *holder2;

	while (environ[i])
	{
		holder = my_strdup(environ[i]);
		res = strtok(holder, "=");
		if (res && my_strcmp(key, res) == 0)
		{
			res = strtok(NULL, "=");
			if (!res)
			{
				free(holder);
				return (NULL);
			}
			holder2 = my_strdup(res);
			free(holder);
			return (holder2);
		}
		free(holder);
		i++;
	}
	return (NULL);
}
