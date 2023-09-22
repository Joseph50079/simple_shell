#include "shell.h"

/**
 * print_cmd_err - Print a command not found error message.
 * @info: A pointer to the hsh structure.
 */
void print_cmd_err(hsh *info)
{
	char *arr = ": not found\n", *mem;
	char *len = _itoa(info->count);
	int i = my_strlen(info->av[0]), x = my_strlen(info->args[0]);
	int l = my_strlen(len), a = my_strlen(arr);

	mem = malloc(sizeof(char) * (i + x + l + a + 7));
	my_strcpy(mem, info->av[0]);
	my_strcat(mem, ": ");
	my_strcat(mem, len);
	my_strcat(mem, ": ");
	my_strcat(mem, info->args[0]);
	my_strcat(mem, arr);

	print_str(mem, 2);
	/*print_str(": ", 2);
	print_str(len, 2);
	print_str(": ", 2);
	print_str(info->args[0], 2);
	print_str(arr, 2);*/

	free(mem);
	free(len);
}

/**
 * err_putchar - Print a character to standard error.
 * @c: The character to print.
 */
void err_putchar(char c)
{
	ssize_t f;

	f = write(2, &c, 1);
	if (f == -1)
	{
		return;
	}
}

/**
 * _itoa - Convert an integer to a string.
 * @num: The integer to convert.
 *
 * Return: A pointer to the converted string, or NULL on failure.
 */
char *_itoa(int num)
{
	char str[20], *ptr;
	int base = 10, i = 0, rem;

	while (num != 0)
	{
		rem = num % base;
		str[i++] = (rem > 9) ? (rem - 10) + 'a' : rem + '0';
		num = num / base;
	}

	str[i] = '\0';
	reverse(str, i);
	ptr = my_strdup(str);
	return (ptr);
}

/**
 * reverse - Reverse a string.
 * @str: The string to reverse.
 * @length: The length of the string.
 */
void reverse(char str[], int length)
{
	int start = 0;
	int end = length - 1;
	char temp;

	while (start < end)
	{
		temp = str[start];
		str[start] = str[end];
		str[end] = temp;
		start++;
		end--;
	}
}

