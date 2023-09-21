#include "shell.h"

/**
 * change_directory - function to change directory
 * @dir: token_array
 * @environ: environment variable
 * Return: void
 */

void change_directory(char *dir, char **environ)
{
	char cwd[MAX_PATH_LENGTH];

	if (dir == NULL || _strcmp(dir, "") == 0)
	{
		dir = _getenv("HOME", environ);
	}
	else if (_strcmp(dir, "-") == 0)
	{
		dir = _getenv("OLDPWD", environ);
	}
	if (chdir(dir) != 0)
	{
		perror("chdir function failed");
		return;
	}
	else
	{
		getcwd(cwd, sizeof(cwd));
		setenv("OLDPWD", _getenv("PWD", environ), 1);
		setenv("PWD", cwd, 1);
	}
}
