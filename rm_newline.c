#include "shell.h"
/**
 * rm_newline - function that remove newline
 * character from user input and replaces it with NULL byte.
 * @getline_buffer: user input
 * Return: void
 */
void rm_newline(char *getline_buffer)
{
	size_t len;


	len = _strlen(getline_buffer);
	if (len > 0 && getline_buffer[len - 1] == '\n')
	{
		getline_buffer[len - 1] = '\0';
	}
}
