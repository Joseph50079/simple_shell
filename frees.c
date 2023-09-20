#include "shell.h"

/**
 * free_args - Frees an array of strings.
 * @tokenized: The array of strings to be freed.
 */
void free_args(char **tokenized)
{
	int i = 0;

	if (tokenized != NULL)
	{
		while (tokenized[i])
		{
			free(tokenized[i]);
			i++;
		}
		free(tokenized);
	}
}

/**
 * free_list - Frees a linked list.
 * @head: A pointer to the head of the list.
 */
void free_list(list_t *head)
{
	list_t *node, *ptr;

	node = head;
	while (node)
	{
		ptr = node->next;
		free(node->str);
		free(node);
		node = ptr;
	}
	head = NULL;
}

void sh_free(hsh *info)
{
	if (info->args != NULL)
	{
		free(info->arg);
		free_args(info->args);
		info->path = NULL;
	}

	if (info->envir != NULL)
	{
		free_list(info->envir);
		free(info->env);
	}
}


