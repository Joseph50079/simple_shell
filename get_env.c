#include "shell.h"

/**
 * _env - Create an array of environment variables.
 * @info: A pointer to the hsh structure.
 *
 * Return: An array of environment variables or NULL on failure.
 */
char **_env(hsh *info)
{
	char **temp;
	int i = 0, j = 0;
	list_t *ptr = NULL;

	ptr = info->environ;
	temp = malloc(sizeof(char *) * (info->node_len + 1));
	if (temp == NULL)
		return (NULL);

	while (ptr)
	{
		temp[i] = malloc(sizeof(char) * (my_strlen(ptr->str) + 1));
		if (temp[i] == NULL)
		{
			while (temp[j])
			{
				free(temp[j]);
				j++;
			}
			free(temp);
			return (NULL);
		}

		my_strcpy(temp[i], ptr->str);
		ptr = ptr->next;
		i++;
	}

	temp[i] = NULL;
	info->env = temp;
	return (temp);
}

/**
 * _getenv - Get the value of an environment variable.
 * @path: The name of the environment variable to find.
 * @envirn: An array of environment variables.
 *
 * Return: The value of the environment variable or NULL if not found.
 */
char *_getenv(char *path, char **envirn)
{
	char *env_cp;
	int i;
	char *var, *val = NULL;

	if (envirn == NULL)
	{
		return (NULL);
	}

	for (i = 0; envirn[i] != NULL; i++)
	{
		env_cp = my_strdup(envirn[i]);

		var = sstrtok(env_cp, "=");
		if (my_strcmp(var, path) == 0)
		{
			val = sstrtok(NULL, "=");
			free(env_cp);
			return (val);
		}
		free(env_cp);
	}
	return (val);
}

