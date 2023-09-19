#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "shell.h"

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
        return NULL;
    }
  
      while (*last != '\0' && strchr(delim, *last))
      {
        last++;
      }

      if (*last == '\0')
      {
        last = NULL;
        return(NULL);
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

 void _sputchar(char c)
{
  int check;
  check = write(1, &c, 1);
  if(check == -1)
  {
    printf("Error in output.");
  }
}

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
