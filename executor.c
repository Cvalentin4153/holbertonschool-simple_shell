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
	char *full_path = get_full_path(environ, args[0]);

	if (!full_path)
	{
		fprintf(stderr, "hsh: Command not found\n");
		*last_status = 127;
		return;
	}

	pid = fork();
	if (pid == 0)
	{
		execve(full_path, args, environ);
		perror("Error");
		free_full_path(full_path, args[0]);
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

	free_full_path(full_path, args[0]);
}
