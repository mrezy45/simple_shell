#include "shell.h"

/**
 * error_message - function prints error message
 * @args: first user input standard input
 * @infi_loop_count: count number of the infinite iteration.
 * Return: void
 */
void error_message(char *args, int infi_loop_count)
{

	write(2, "hsh: ", 5);
	_putchar(infi_loop_count + '0');
	write(2, ": ", 2);
	write(2, args, _strlen(args));
	write(2, ": ", 2);
	write(2, "not found", 9);
	write(2, "\n", 1);
}


/**
 * permission_denied - function that prints the  permission denied message
 * @args: first command in user inputs
 * @infi_loop_count: number of infinite iteration count
 * Return: void
 */
void permission_denied(char *args, int infi_loop_count)
{

	write(2, "hsh: ", 5);
	_putchar(infi_loop_count + '0');
	write(2, ": ", 2);
	write(2, args, _strlen(args));
	write(2, ": ", 2);
	write(2, "permission denied", 17);
	write(2, "\n", 1);
}


/**
 * _putchar - function that prints character.
 * @count_input_strings: number of strings input
 * Return: void
 */
int _putchar(char count_input_strings)
{
	return (write(2, &count_input_strings, 1));
}
