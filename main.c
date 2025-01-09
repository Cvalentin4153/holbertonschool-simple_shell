#include "shell.h"
#define MAX_ARGS 10
/**
 * main - Entry point of the shell program
 * Return: 0 on successful execution
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
		if (!is_interactive)
			break;
	}
	free(line);
	return (last_status);
}
