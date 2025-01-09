#include "shell.h"
/**
 * get_full_path - Resolves the full path of a command
 * @environ: Environment variables
 * @command: Command to resolve
 * Return: Full path if found, NULL otherwise
 */
char *get_full_path(char **environ, char *command)
{
	if (strchr(command, '/') != NULL)
	{
		if (access(command, X_OK) == 0)
			return (command);
		return (NULL);
	}
	return (find_command(environ, command));
}
