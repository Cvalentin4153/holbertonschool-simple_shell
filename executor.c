#include "shell.h"

/**
 * find_command - Searches for a command in the PATH
 * @command: The command to search for
 *
 * Description:
 * Searches the directories listed in the PATH environment variable
 * for the specified command. If found, returns the full path to
 * the command; otherwise, returns NULL.
 *
 * Return: Full path to the command or NULL if not found
 */

char *find_command(char *command)
{
	char *path = getenv("PATH");
	char *dir, *full_path;
	size_t len;

	if (!path)
	{
		fprintf(stderr, "PATH environment variable not found\n");
		return (NULL);
	}

	path = strdup(path);
	dir = strtok(path, ":");

	while (dir != NULL)
	{
		len = strlen(dir) + strlen(command) + 2;
		full_path = malloc(len);
		if (!full_path)
		{
			free(path);
			return (NULL);
		}

		sprintf(full_path, "%s/%s", dir, command);

		if (access(full_path, X_OK) == 0)
		{
			free(path);
			return(full_path);
		}

		free(full_path);
		dir = strtok(NULL, ":");
	}
	free(path);
	return (NULL);
}

/**
 * execute_command - Executes a command with arguments
 * @args: Array of strings (command and its arguments)
 *
 * Description:
 * Creates a child process to execute the specified command with
 * the provided arguments. The parent process waits for the child
 * to complete execution.
 *
 * Return: void
 */
void execute_command(char **args)
{
	pid_t pid;
	int status;
	char *full_path;

	full_path = find_command(args[0]); // Locate the command in PATH
	if (!full_path)
	{
		fprintf(stderr, "%s: Command not found\n", args[0]);
		return;
	}

	pid = fork();
	if (pid == 0) // Child process
	{
		if (execve(full_path, args, environ) == -1)
		{
			perror("Error");
			free(full_path);
			exit(EXIT_FAILURE);
		}
	}
	else if (pid > 0) // Parent process
	{
		waitpid(pid, &status, 0);
	}
	else
	{
		perror("Fork failed");
	}
	free(full_path);
}
