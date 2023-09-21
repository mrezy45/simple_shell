#include "shell.h"

/**
 * print_environment - function that prints the environment
 * @environ: user environment
 * Return: void
 */
void print_environment(char **environ)
{
	int i;
	size_t lenght;

	for (i = 0; environ[i] != NULL; i++)
	{
		lenght = _strlen(environ[i]);
		write(STDOUT_FILENO, environ[i], lenght);
		write(STDOUT_FILENO, "\n", 1);
	}
}
