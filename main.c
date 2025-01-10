#include "shell.h"
#define MAX_ARGS 10
/**
 * main - Entry point for the simple shell program
 * @argc: Argument count (unused)
 * @argv: Argument vector (unused)
 * @environ: Array of environment variables
 *
 * Description:
 * This function implements a simple shell program. It continuously
 * displays a prompt in interactive mode and waits for user commands.
 * In non-interactive mode, it processes commands from standard input.
 * It handles built-in commands like `exit` and `env` and executes
 * external commands using `execve`. The shell exits on EOF (Ctrl+D).
 *
 * Return: 0 on successful execution, or the exit status of the last command.
 */
int main(int argc, char **argv, char **environ)
{
	char *line = NULL;
	size_t len = 0;
	ssize_t nread;
	char *args[MAX_ARGS];
	int last_status = 0;
	int is_interactive = isatty(STDIN_FILENO);

	(void)argc;
	(void)argv;

	while (1)
	{
		if (is_interactive)
			write(STDOUT_FILENO, "$ ", 2);

		nread = getline(&line, &len, stdin);
		if (nread == -1)
		{
			if (is_interactive)
				write(STDOUT_FILENO, "Exiting shell...\n", 17);
			break;
		}
		if (nread > 0)
			line[nread - 1] = '\0';

		tokenize_input(line, args);
		if (args[0] != NULL)
		{
			if (handle_builtin(args, environ, &last_status))
				continue;
			execute_command(environ, args, &last_status);
		}
	}
	free(line);
	return (last_status);
}
