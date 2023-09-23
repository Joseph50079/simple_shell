#include "shell.h"

/**
 * print_env - Print the environment variables.
 * @info: A pointer to the hsh structure.
 *
 * Return: 0 on success, -1 on failure.
 */
int print_env(hsh *info)
{
	int i = 0;
	char *env;

	if (info->envir == NULL)
	{
		return (0);
	}

	while (info->envir[i] != NULL)
	{
		env = info->envir[i];
		print_str(env, 1);
		_sputchar('\n');
		i++;
	}
	return (0);
}

/**
 * exit_fun - Handle the exit built-in command.
 * @info: A pointer to the hsh structure.
 *
 * Return: This function does not return.
 */
int exit_fun(hsh *info)
{
	int status = 0;
	char *at;

	if (info->args[1])
	{
		if (info->args != NULL)
		{
			at = info->args[1];
			status = atoi(at);
			free(*info->buffer);
			free_args(info->args);
			info->path = NULL;
			sh_free(info, 1);
		}
	}
	
	else
	{
		if (info->args != NULL)
		{
			free(*info->buffer);
			sh_free(info, 0);
			sh_free(info, 1);
		}
		
	}

	
	exit(status);
}

