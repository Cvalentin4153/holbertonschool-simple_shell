#include "shell.h"


/**
 * exit_shell - Terminates the shell program
 *
 * Description:
 * This function is called when the user types "exit".
 *
 * Return: Does not return (exits the program)
 */
void exit_shell(void)
{
	exit(0);
}

/**
 * change_directory - Handles the `cd` command
 * @args: Array of strings (command and arguments)
 *
 * Description:
 * Changes the current working directory.
 * If no argument is provided, changes to the HOME directory.
 * If an invalid directory is provided, displays an error message.
 *
 * Return: 0 on success, -1 on failure
 */
int change_directory(char **args)
{
	char *dir;

	if (args[1] == NULL)
	{
		dir = getenv("HOME");
		if (dir == NULL)
		{
			fprintf(stderr, "cd: HOME not set\n");
			return (-1);
		}
	}
	else
	{
		dir = args[1];
	}

	if (chdir(dir) != 0)
	{
		perror("cd");
		return (-1);
	}
	return (0);
}

/**
 * print_env - Prints the current environment variables
 *
 * Description:
 * Iterates through the `environ` global variable and prints each
 * environment variable.
 *
 * Return: void
 */
void print_env(void)
{
	extern char **environ;
	int i = 0;

	if (environ == NULL)
	{
		return;
	}
	while (environ[i])
	{
		printf("%s\n", environ[i]);
		i++;
	}
}
