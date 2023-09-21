#include "shell.h"

/**
 * builtin - Check if a command is a built-in and execute it.
 * @info: A pointer to the hsh structure.
 *
 * Return: The exit status of the built-in command, or -1 if not found.
 */
int builtin(hsh *info)
{
	int i = 0, check;
	builtins func[] = {
		{"env", print_env},
		{"exit", exit_fun},
		{NULL, NULL}
	};

	while (func[i].f != NULL)
	{
		if (my_strcmp(func[i].str, info->args[0]) == 0)
		{
			check = func[i].f(info);
			return (check);
		}
		i++;
	}
	return (-1);
}

