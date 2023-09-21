#include "shell.h"

/**
 * compare_first_five - function that compares the first-five charactars
 * @str1: string command from user
 * @str2: prefix
 * Return: integer
 */

int compare_first_five(char *str1, char *str2)
{
	char sub1[6], sub2[6];

	if (_strlen(str1) < 5 || _strlen(str2) < 5)
	{
		return (0);
	}
	_strncpy(sub1, str1, 5);
	_strncpy(sub2, str2, 5);
	sub1[5] = sub2[5] = '\0';

	return (_strcmp(sub1, sub2) == 0);
}

/**
 * _strcheck - checks for strings
 * @args: string to be checked
 * * Return: string pointer
 */

int _strcheck(char *args)
{
	char *prefix;

	prefix = "/bin/";

	if (_strcmp("env", args) == 0)
	{
		return (1);
	}
	if (_strcmp("cd", args) == 0)
	{
		return (2);
	}
	if (compare_first_five(args, prefix))
	{
		return (3);
	}
	else if (_strcmp("exit", args) != 0 && _strcmp("env", args) != 0)
	{
		return (4);
	}
	return (5);
}

/**
 * _getenv - function that retrieves an environment variable values.
 * @name: name of the env vairiable
 * @environ: user environment
 * Return: pointer to  string.
 */
char *_getenv(char *name, char **environ)
{
	char **env;
	char *var, *equals;
	ssize_t name_len;

	for (env = environ; *env != NULL; ++env)
	{
		var = *env;
		equals = _strchr(var, '=');
		if (equals != NULL)
		{
			name_len = equals - var;
			if (name_len == _strlen(name) && _strncmp(var, name, name_len) == 0)
			{
				return (equals + 1);
			}
		}
	}
	return (NULL);
}

/**
 * path_directories - function that gets the values of PATH.
 * @environ: user environment
 * Return: pointer to a string
 */
char *path_directories(char **environ)
{
	char *path_env = NULL, *path_copy = NULL, *var_name;

	var_name = "PATH";
	path_env = _getenv(var_name, environ);
	if (path_env == NULL)
	{
		perror("could not retrieve PATH environment variables");
		exit(errno);
	}
	path_copy = malloc(MAX_PATH_LENGTH * sizeof(char));
	if (path_copy == NULL)
	{
		perror("memory allocation to path_copy failed");
		exit(errno);
	}
	path_copy[MAX_PATH_LENGTH - 1] = '\0';
	_strcpy(path_copy, path_env);

	return (path_copy);
}

/**
 * find_in_path - function that finds the input command in PATH
 * @str: directories of PATH
 * @args: user input command
 * @av: array of input tokens
 * @environ: user environ
 * @count: count number of the iteration of infinite loop
 * Return: void
 */

void find_in_path(char *args, char *str, char **av, char **environ, int count)
{
	char *dir = NULL, *full_path = NULL;
	pid_t child_pid;
	int status, exec_found = 0;

	dir = strtok(str, ":");
	while (dir != NULL && !compare_first_five(args, "/bin/"))
	{
		full_path = malloc(_strlen(dir) + _strlen(str) + 2);
		if (full_path == NULL)
		{
			perror("memory allocation to full_path failed");
			exit(errno);
		}
		_strcpy(full_path, dir);
		_strcat(full_path, "/");
		_strcat(full_path, args);
		full_path[_strlen(full_path)] = '\0';
		if (access(full_path, X_OK) == 0)
		{
			exec_found = 1;
			child_pid = fork();
			if (child_pid == -1)
				perror("fork function failed");
			else if (child_pid == 0 && execve(full_path, av, environ) == -1)
			{
				perror("execve failed");
				exit(errno);
			}
			else
			{
				wait(&status);
				free(full_path);
				break;
			}
		}
		free(full_path);
		dir = strtok(NULL, ":");
	}
	if (!exec_found)
		error_message(args, count);
}
