#include "shell.h"
/**
 * handle_builtin - Handles built-in shell commands
 * @args: Tokenized arguments
 * @environ: Environment variables
 * @last_status: Pointer to the last status variable
 * Return: 1 if a built-in command was executed, 0 otherwise
 */
int handle_builtin(char **args, char **environ, int *last_status)
{
	if (strcmp(args[0], "exit") == 0)
		exit(*last_status);

	if (strcmp(args[0], "env") == 0)
	{
		print_env(environ);
		return (1);
	}
	return (0);
}
