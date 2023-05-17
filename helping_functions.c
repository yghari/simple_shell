#include "shell.h"

char *_strcat(char *dest, char *src)
{
    char *hold;
    int i = 0;
    int j = 0;

    hold = malloc(sizeof(char) * (_strlen(dest) + _strlen(src) + 2));
   
    if (hold == NULL)
    {
        return (NULL);
    }
    while (dest[i])
    {
        hold[i] = dest[i];
        i++;
    }
    hold[i] = '/';
    i++;
    while (src[j])
    {
        hold[i] = src[j];
        i++;
        j++;
    }
    hold[i] = '\0';
    return (hold);
}

/**
 * _strlen - returns the length of a string
 * @s: the string to get the length of
 * Return: the length of s
 */
int _strlen(char *s)
{
    int i = 0;
    while (s[i] != '\0')
    {
        i++;
    }
    return (i);
}

/**
 * _strncmp - compares two strings up to a specified length
 * @s1: the first string to compare
 * @s2: the second string to compare
 * @n: the maximum number of characters to compare
 * Return: an integer less than, equal to, or greater than zero if s1 is found,
 * respectively, to be less than, to match, or be greater than s2
 */
int _strncmp(const char *s1, const char *s2, size_t n)
{
    size_t i;
  
    for (i = 0; i < n; i++)
    {
        if (s1[i] == '\0' || s2[i] == '\0' || s1[i] != s2[i])
        {
            return (s1[i] - s2[i]);
        }
    }
    return (0);
}

/**
 * _strdup - returns a pointer to a newly allocated space in memory,
 * which contains a copy of the string given as a parameter.
 * @str: string to be duplicated.
 *
 * Return: pointer to duplicated string or NULL if str is NULL or
 * if memory allocation fails.
 */
char *_strdup(char *str)
{
	char *dup;
	unsigned int i, len = 0;

	if (str == NULL)
		return (NULL);

	while (str[len])
		len++;

	dup = malloc(sizeof(char) * (len + 1));
	if (dup == NULL)
		return (NULL);

	for (i = 0; i < len; i++)
		dup[i] = str[i];
	dup[i] = '\0';

	return (dup);
}
