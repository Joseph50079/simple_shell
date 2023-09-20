#include "shell.h"

/**
 * create_environ - Create a linked list of environment variables.
 * @info: A pointer to the hsh structure.
 */
void create_environ(hsh *info)
{
	int i;
	list_t *head = NULL;

	for (i = 0; environ[i] != NULL; i++)
	{
		head = add_node_end(&head, environ[i]);
	}
	info->node_len = i;
	info->environ = head;
}

