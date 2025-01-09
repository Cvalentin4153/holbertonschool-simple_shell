#include "shell.h"
char **environ;
int last_status = 0;

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
	char *path = get_env("PATH");
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

int execute_command(char **args)
{
	pid_t pid;
	int status;
	char *full_path;

	if (strchr(args[0], '/') != NULL)
	{
		full_path = args[0];
		if (access(full_path, X_OK) != 0)
		{
			fprintf(stderr, "%s: Command not found\n", args[0]);
			return (127);
		}
	}
	else
	{
		full_path = find_command(args[0]);
		if (!full_path)
		{
			fprintf(stderr, "%s: Command not found\n", args[0]);
			return (127);
		}
	}

	pid = fork();
	if (pid == 0)
	{
		if (execve(full_path, args, environ) == -1)
		{
			perror("Error");
			if (full_path != args[0])
				free(full_path);
			exit(126);
		}
	}
	else if (pid > 0)
	{
		waitpid(pid, &status, 0);
		if (WIFEXITED(status))
			last_status = WEXITSTATUS(status);
		else
			last_status = 1;
	}
	else
	{
		perror("Fork failed");
		last_status = 1;
	}

	if (full_path != args[0])
		free(full_path);
	return (last_status);
}
