#include "shell.h"


int ch(char *line, size_t size, ssize_t read_size, char **lineptr, size_t *n);
/**
 * _getline - custom getline function
 * @lineptr: pointer to the line read
 * @stream: file descriptor
 * @n: size of buffer
 * Return: size if read line
 */

ssize_t _getline(char **lineptr, size_t *n, int fd)
{
        static char Buffer[BUFFER_S];
        static size_t position, buffer_size;
        char *line = *lineptr, *new_line;
        size_t size = *n;
        ssize_t read_size = 0;

        position = 0;
        buffer_size = 0;
        if (lineptr == NULL || size == 0)
        {
                size = BUFFER_S;
                line = malloc(sizeof(char) * size);
                if (line == NULL)
                        return (-1);
        }
        while (1)
        {
                if (position >= buffer_size)
                {
                        buffer_size = read(fd, Buffer, BUFFER_S);
                        position = 0;
                }
                if (buffer_size == 0)
                        break;
                while (position < buffer_size)
                {
                        if ((size_t)read_size >= size - 1)
                        {
                                size *= 2;
                                new_line = realloc(line, size);
                                if (new_line == NULL)
                                {
                                        free(line);
                                        return (-1);
                                }
                                line = new_line;
                        }
                        line[read_size] = Buffer[position];
                        if (ch(line, size, read_size, lineptr, n) != -1)
                                return (read_size);
                }
        }
        if (read_size == 0)
        {
                free(line);
                *n = 0;
                *lineptr = NULL;
        }
        return (read_size);
}

/**
 * ch - check for _getline
 * @line: line
 * @size: size
 * @read_size: reaf
 * @lineptr: line ptr
 * @n: n
 * Return: 0
 */

int ch(char *line, size_t size, ssize_t read_size, char **lineptr, size_t *n)
{
        if (line[read_size - 1] == '\n')
        {
                line[read_size] = '\0';
                *lineptr = line;
                *n = size;
                return (0);
        }
        else
                return (-1);
}