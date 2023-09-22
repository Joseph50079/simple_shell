#include "shell.h"

/**
 * parser - Tokenize a buffer into an array of strings.
 * @buffer: The input buffer to tokenize.
 *
 * Return: An array of strings containing the tokens or NULL on failure.
 */
char **parser(char *buffer)
{
	int i = 0, x = 0, j;
	char *token, **tokenized, *delim = " \n\t ", *buf;

	buf = my_strdup(buffer);
	token = sstrtok(buf, delim);
	while (token)
	{
		x++;
		token = sstrtok(NULL, delim);
	}
	tokenized = malloc(sizeof(char *) * (x + 1));
	if (tokenized == NULL)
	{
		free(buf);
		return (NULL);
	}
	my_strcpy(buf, buffer);
	token = sstrtok(buf, delim);
	i = 0;
	while (token)
	{
		tokenized[i] = my_strdup(token);
		if (tokenized[i] == NULL)
		{
			free(buf);
			for (j = 0; j < i; j++)
			{
				free(tokenized[j]);
			}
			free(tokenized[j]);
			free(tokenized);
			return (NULL);
		}
		token = sstrtok(NULL, delim);
		i++;
	}
	tokenized[i] = NULL;

	free(buf);
	return (tokenized);
}

/**
 * process - Execute a command.
 * @info: A pointer to the hsh structure.
 */
void process(hsh *info)
{
	pid_t child_id;
	int status;

	child_id = fork();
	if (child_id == 0)
	{
		if (execve(info->path, info->args, _env(info)) == -1)
		{
			print_cmd_err(info);
			sh_free(info, 0);
			exit(127);
		}
	}
	else
	{
		wait(&status);
	}
}

/**
 * executor - Execute commands in a loop.
 * @info: A pointer to the hsh structure.
 * @argv: An array of argument strings.
 *
 * Return: The exit status of the last executed command or -1 on failure.
 */
int executor(hsh *info, char **argv)
{	char *buffer = NULL;
	size_t n = 0;
	ssize_t read_num;
	int i = 0, check;

	info->count = 0;
	while (1)
	{	info->count++;
		if (info->interact)
		{	prompt();
			fflush(stdout);	}
		read_num = getline(&buffer, &n, stdin);
		if (read_num == -1)
		{	sh_free(info, 1);
			free(buffer);
			if (info->interact)
			{	_sputchar('\n');	}
			return (0);	}
		info->av = argv;
		info->args = parser(buffer);
		if (info->args[i] == NULL)
		{
			free_args(info->args);
			continue;
		}
		check = builtin(info);
		if (check == -1)
		{	info->path = path_tok(info);
			if (info->path == NULL)
			{	print_cmd_err(info);	}
			else
			{	process(info);
				free(info->path);	}
		}	sh_free(info, 0);
	}
	if (buffer != NULL)
	{free(buffer);	}
	return (0);
}

/**
 * path_tok - Find the full path of a command.
 * @info: A pointer to the hsh structure.
 *
 * Return: The full path of the command or NULL if not found.
 */
char *path_tok(hsh *info)
{
	char *pass, *path = NULL, *command;
	char *token, *name;
	int i = my_strlen(info->args[0]);
	struct stat st;
	char **env = _env(info);

	path = getenv("PATH");
	if (path == NULL)
	{
		return (NULL);
	}

	pass = strdup(path);
	token = sstrtok(pass, ":");
	if (info->args[0] != NULL)
	{
		command = my_strdup(info->args[0]);
		if (stat(command, &st) == 0)
		{
			free(pass);
			return (command);
		}
	}
	while (token != NULL)
	{
		name = malloc(sizeof(char) * (my_strlen(token) + 2 + i));
		if (name == NULL)
		{
			free(pass);
			free(command);
			perror("Error allocating space\n");
			return (NULL);
		}
		my_strcpy(name, token);
		my_strcat(name, "/");
		my_strcat(name, command);
		if (stat(name, &st) == 0)
		{
			free(pass);
			free(command);
			return (name);
		}
		token = sstrtok(NULL, ":");
		free(name);
	}
	free(pass);
	free(command);
	/*free_args(_env(info));*/
	return (token);
}

