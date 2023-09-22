#include "shell.h"

/**
 * _env - Create an array of environment variables.
 * @info: A pointer to the hsh structure.
 *
 * Return: An array of environment variables or NULL on failure.
 */
char **_env(hsh *info)
{
    int i = 0, j;
    list_t *ptr = NULL;

    ptr = info->environ;
    info->env = malloc(sizeof(char *) * (info->node_len ));
    if (info->env == NULL)
        return (NULL);

    while (ptr)
    {
        info->env[i] = my_strdup(ptr->str);
        if (info->env[i] == NULL)
        {
            for (j = 0; j < i; j++)
            {
                free(info->env[j]);
            }
            free(info->env[j]);
            free(info->env);
            return (NULL);
        }
        ptr = ptr->next;
        i++;
    }

    info->env[i] = NULL;
	
    return (info->env);
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

