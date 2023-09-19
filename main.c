#include "shell.h"

/**
 * main - Entry point of the shell program.
 * @ac: The number of arguments.
 * @argv: An array of argument strings.
 *
 * Return: The exit status of the shell.
 */
int main(int ac, char **argv)
{
	int status;
	hsh info[] = {INIT};
	int fd = 0;
	int is_interactive;

	is_interactive = isatty(fd);

	(void)ac;

	info->interact = is_interactive;
	create_environ(info);
	status = executor(info, argv);

	return (status);
}

/**
 * prompt - Display the shell prompt.
 */
void prompt(void)
{
	char *n = "@me$ ";

	if (1)
	{
		if (write(STDOUT_FILENO, n, 6) == -1)
		{
			perror("Error: ");
		}
	}
}

