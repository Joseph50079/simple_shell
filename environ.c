#include "shell.h"

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
