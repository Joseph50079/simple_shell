#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "shell.h"

/**
 * sstrtok - Custom strtok function.
 * @str: The string to tokenize.
 * @delim: The delimiter characters.
 *
 * Return: A pointer to the next token or NULL if there are no more tokens.
 */
char *sstrtok(char *str, char *delim)
{
	static char *last;
	char *bigi;

	if (str != NULL)
	{
		last = str;
	}
	else if (last == NULL)
	{
		return (NULL);
	}

	while (*last != '\0' && strchr(delim, *last))
	{
		last++;
	}

	if (*last == '\0')
	{
		last = NULL;
		return (NULL);
	}

	bigi = last;
	while (*last != '\0' && !(strchr(delim, *last)))
	{
		last++;
	}

	if (*last != '\0')
	{
		*last = '\0';
		last++;
	}

	return (bigi);
}

/**
 * _sputchar - Custom putchar function.
 * @c: The character to print.
 */
void _sputchar(char c)
{
	int check;

	check = write(1, &c, 1);
	if (check == -1)
	{
		printf("Error in output.");
	}
}

/**
 * print_str - Custom function to print a string.
 * @str: The string to print.
 * @i: The file descriptor to write to.
 */
void print_str(char *str, int i)
{
	ssize_t count;
	size_t len = my_strlen(str) + 1;

	count = write(i, str, len);
	if (count == -1)
	{
		return;
	}
}

