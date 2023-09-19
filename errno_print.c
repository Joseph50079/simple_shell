#include "shell.h"


void print_cmd_err(hsh *info)
{
  char *arr = ": not found\n";
  char *len = _itoa(info->count);
  print_str(info->av[0], 2);
  print_str(": ", 2);
  print_str(len, 2);
  print_str(": ", 2);
  print_str(info->arg, 2);
  print_str(arr, 2);
}

void err_putchar(char c)
{
  ssize_t f;
  f = write(2, &c, 1);
  if (f == -1)
  {
    return;
  }
}

char *_itoa(int num)
{
  char str[20], *ptr;
  int base = 10, i = 0;

  while (num != 0) {
        int rem = num % base;
        str[i++] = (rem > 9) ? (rem - 10) + 'a' : rem + '0';
        num = num / base;
    }
  
  str[i] = '\0';
  reverse(str, i);
  ptr = my_strdup(str);
  return (ptr);
}


void reverse(char str[], int length)
{
    int start = 0;
    int end = length - 1;
    while (start < end)
    {
        char temp = str[start];
        str[start] = str[end];
        str[end] = temp;
        start++;
        end--;
    }
}
