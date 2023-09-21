#include "shell.h"

/**
 * _strlen - function gets length of string
 * @str: the string whose length is got
 *
 * Return: the length of string
 */

int _strlen(char *str)
{
	int len = 0;

	if (str == NULL)
		return (-1);
	while (*str != '\0')
	{
		len++;
		str++;
	}
	return (len);
}

/**
 * _strcpy - copies strings
 * @dest: destination of copying action
 * @src: source
 *
 * Return: pointer to destination string
 */

char *_strcpy(char *dest, char *src)
{
	char *ptr = dest;
	int i = 0;

	if (src == NULL)
		src = "";
	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (ptr);
}

/**
 * _strcmp - compares two strings
 * @s1: first string
 * @s2: second string
 *
 * Return: 0, if the two strings are the same
 * else != 0
 */
int _strcmp(char *s1, char *s2)
{
	int i = 0;

	while (s1[i] != '\0' || s2[i] != '\0')
	{
		if (s1[i] != s2[i])
		{
			return ((s1[i] + '0') - (s2[i] + '0'));
		}
		i++;
	}
	return (0);
}



/**
 * _strcat - program that concatenates two strings
 * @dest: the destination string
 * @src: the source string
 * Return: pointer to the resulting string dest
 */

char *_strcat(char *dest, char *src)

{
	int dlen = 0, i;

	while (dest[dlen])
	{
		dlen++;
	}

	for (i = 0; src[i] != 0; i++)
	{
		dest[dlen] = src[i];
		dlen++;
	}
	dest[dlen] = '\0';
	return (dest);
}

/**
 * _strncpy - function that copies a string
 * @dest: buffer for storing the string copy
 * @src: source string
 * @n: maximum number of bytes copied from src.
 * Return: pointer to the resulting string dest'
 */
char *_strncpy(char *dest, char *src, int n)
{
	int index = 0;
	int src_len = 0;

	while (src[index++])
		src_len++;
	for (index = 0; src[index] && index < n; index++)
		dest[index] = src[index];
	for (index = src_len; index < n; index++)
		dest[index] = '\0';

	return (dest);
}
