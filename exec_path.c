#include "shell.h"

/**
 * exec_path - function that prints the absolute path
 * @args: token_array[0]
 * @token_array: users input
 * @environ: users environ
 * @count: count number of iteration of infinite loop
 * Return: void
 */
void exec_path(char *args, char **token_array, char **environ,
		int count)
{
	pid_t child_pid;
	int status;
	ssize_t a, x;

	x = access(args, X_OK);
	if (x == 0)
	{
		child_pid = fork();
		if (child_pid == -1)
		{
			perror("fork function at absolute path failed");
			exit(errno);
		}
		else if (child_pid == 0)
		{
			a = execve(args, token_array, environ);
			if (a == -1)
			{
				permission_denied(args, count);
				exit(errno);
			}
		}
		else
		{
			wait(&status);
		}
	}
	if (x == -1)
	{
		error_message(args, count);
		exit(errno);
	}
}
