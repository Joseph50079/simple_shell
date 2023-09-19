#include "shell.h"

int print_env(hsh *info)
{
  int i = 0;
  char *env;
  
  info->env = _env(info);

  if (info->env == NULL)
  {
    return (-1);
  }

  while (info->env[i])
    {
      env = info->env[i];
      print_str(env, 1);
      _sputchar('\n');
      i++;
    }
  return (0);
}


int exit_fun(hsh *info)
{
  int status = 0;
  char *at;
  if (info->args != NULL)
  {
    at = info->args[1];
    status = atoi(at);
    free(info->arg);
    free_args(info->args);
  }
  if (info->environ != NULL)
  {
    free_list(info->environ);
    free(info->env);
  }
  if (info->av != NULL)
  {
    free_args(info->av);
  }
  if (info->path != NULL)
  {
    free(info->path);
  }

  exit(status);
}
