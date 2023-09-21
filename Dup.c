#include "shell.h"

/**
 * duplicate - duplicates a string
 * @buff: string to be duplicated
 *
 * Return: pointer to an array of strings.
 */

char *duplicate(char *buff)
{
	char *buffer;

	buffer = malloc((_strlen(buff) + 1) * sizeof(char));
	if (buffer == NULL)
	{
		perror("memory allocation to buffer failed");
		exit(errno);
	}
	buffer[0] = '\0';

	_strcpy(buffer, buff);

	return (buffer);
}
