#include "shell.h"

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
extern char **environ;

void execute_command(char **args)
{
	pid_t pid;
	int status;

	pid = fork();
	if (pid == 0)
	{
		if (execve(args[0], args, environ) == -1)
		{
			perror("Error");
			exit(EXIT_FAILURE);
		}
	}

	else if (pid > 0)
	{
		waitpid(pid, &status, 0);
	}
	else
	{
		perror("Fork failed");
	}
}

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
	return (NULL);

dir = strtok(path, ":");
while (dir != NULL)
{
	len = strlen(dir) + strlen(command) + 2;
	full_path = malloc(len);
	if (!full_path)
		return (NULL);

}
}
