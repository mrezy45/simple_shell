#include "shell.h"

/**
 * main - Entry point in to the shell
 * @ac: argument count
 * @argv: argument vector
 * @environ: global variable
 *
 * Return: 0
 */

int main(int ac, char **argv, char **environ)
{
	int isatty_mode = 0, status, count = 0;
	char *getline_buffer = NULL, *buffer = NULL, **token_array;

	isatty_mode = isatty(STDIN_FILENO);
	while (1)
	{
		count++;
		if (isatty_mode == 1 && ac != 2)
		{
			write(STDOUT_FILENO, "$ ", 2);
		}
		getline_buffer = readline(ac, argv);
		if (getline_buffer == NULL)
		{
			if (isatty_mode == 1)
				write(STDOUT_FILENO, "\n", 1);
			break;
		}
		rm_newline(getline_buffer);
		if (getline_buffer[0] == '\0' || getline_buffer[0] == ' ')
		{
			if (check_spaces(getline_buffer) == NULL)
			{
				free(getline_buffer);
				continue;
			}
		}
		buffer = duplicate(getline_buffer);
		token_array = tokenize(getline_buffer, buffer, NULL);
		if ((_strcmp(token_array[0], "exit") == 0))
		{
			status = exit_status(token_array);
			_free(token_array, getline_buffer, buffer);
			exit(status);
		}
		exec_func(token_array, environ, count);
		_free(token_array, getline_buffer, buffer);
	}
	return (0);
}
