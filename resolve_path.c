#include "shell.h"
/**
 * resolve_path - Resolves the full path of a command
 * @environ: Array of environment variables
 * @command: Command to resolve
 * @last_status: Pointer to the status of the last executed command
 *
 * Description:
 * This function checks if a command is provided as a full or relative path
 * and verifies its existence and executability. If the command does not
 * include a path, it searches for the command in the directories specified
 * by the PATH environment variable.
 *
 * Return: A pointer to the resolved full path of the command, or NULL if
 * the command cannot be found or is not executable.
 */
char *resolve_path(char **environ, char *command, int *last_status)
{
	(void) last_status;

	if (strchr(command, '/'))
	{
		if (access(command, X_OK) == 0)
			return (command);
		return (NULL);
		
	}
	return (find_command(environ, command));
}
