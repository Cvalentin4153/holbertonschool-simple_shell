#include "shell.h"
/**
 * execute_command - Executes a command with arguments
 * @environ: Environment variables
 * @args: Tokenized arguments
 * @last_status: Pointer to the last status variable
 * Return: void
 */
void execute_command(char **environ, char **args, int *last_status)
{
	pid_t pid;
	int status;
	if (strchr(args[0], '/') != NULL)
	{
		if (access(args[0], X_OK) != 0)
		{
			fprintf(stderr, "hsh: Command not found\n");
			*last_status = 127;
			return;
		}
	}
	else
	{
		args[0] = find_command(environ, args[0]);
		if (!args[0])
		{
			fprintf(stderr, "hsh: Command not found\n");
			*last_status = 127;
			return;
		}
	}
	pid = fork();
	if (pid == 0)
	{
		execve(args[0], args, environ);
		perror("Error");
		exit(1);
	}
	else if (pid > 0)
	{
		waitpid(pid, &status, 0);
		*last_status = WEXITSTATUS(status);
	}
	else
	{
		perror("Fork failed");
		*last_status = 1;
	}
}
