#include "shell.h"

/**
 * my_strcmp - Compare two strings.
 * @s1: The first string.
 * @s2: The second string.
 *
 * Return: 0 if the strings are equal, a negative value if s1 < s2,
 *         and a positive value if s1 > s2.
 */
int my_strcmp(const char *s1, const char *s2)
{
	while (*s1 && (*s1 == *s2))
	{
		s1++;
		s2++;
	}

	return (*(unsigned char *)s1 - *(unsigned char *)s2);
}

/**
 * my_strdup - Create a duplicate of a string.
 * @str: The input string.
 *
 * Return: A pointer to a newly allocated copy of the string, or NULL if
 *         memory allocation fails.
 */
char *my_strdup(const char *str)
{
	size_t len = 0;
	char *new_str;

	while (str[len])
		len++;

	new_str = malloc(sizeof(char) * (len + 1));

	if (!new_str)
		return (NULL);

	for (len = 0; str[len]; len++)
		new_str[len] = str[len];

	new_str[len] = '\0';

	return (new_str);
}

/**
 * my_strcpy - Copy a string to another.
 * @dest: The destination string.
 * @src: The source string.
 *
 * Return: A pointer to the destination string.
 */
char *my_strcpy(char *dest, const char *src)
{
	size_t i = 0;

	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}

	dest[i] = '\0';
	return (dest);
}

/**
 * my_strcat - Concatenate two strings.
 * @dest: The destination string.
 * @src: The source string.
 *
 * Return: A pointer to the destination string.
 */
char *my_strcat(char *dest, const char *src)
{
	size_t dest_len = 0;
	size_t i = 0;

	while (dest[dest_len])
		dest_len++;

	while (src[i])
	{
		dest[dest_len + i] = src[i];
		i++;
	}

	dest[dest_len + i] = '\0';

	return (dest);
}

/**
 * my_strlen - Calculate the length of a string.
 * @str: The input string.
 *
 * Return: The length of the string.
 */
size_t my_strlen(const char *str)
{
	size_t len = 0;

	while (str[len])
		len++;

	return (len);
}
