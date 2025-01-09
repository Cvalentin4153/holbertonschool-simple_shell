#include "shell.h"
/**
 * main - Entry point of the shell program
 *
 * Description:
 * Continuously displays a prompt ($) and waits for user commands.
 *
 * Return: 0 on successful execution
 */
int main(void)
{
	char *line = NULL;
	size_t len = 0;
	ssize_t nread;
	char *args[10];
	int i;

	while (1)
	{

		write(STDOUT_FILENO, "$ ", 2);
		nread = getline(&line, &len, stdin);

		if  (nread == -1)
		{
			write(STDOUT_FILENO, "\nExiting shell...\n", 18);
			free(line);
			exit(0);
		}
		if (nread > 0)
			line[nread - 1] = '\0';

		args[0] = strtok(line, " \t");
		i = 1;

		while ((args[i] = strtok(NULL, " \t")) != NULL)
			i++;

		if (args[0] ==  NULL)
			continue;

		if (strcmp(args[0], "exit") == 0)
		{
			free(line);
			exit(0);
		}

		if (strcmp(args[0], "cd") == 0)
		{
			change_directory(args);
			continue;
		}

		if (strcmp(args[0], "env") == 0)
		{
			print_env();
			continue;
		}
		execute_command(args);
	}
	return (0);
}
