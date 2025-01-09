#include "shell.h"
/**
 * print_env - Prints the current environment variables
 * @environ: Environment variables
 * Return: void
 */
void print_env(char **environ)
{
	int i = 0;

	while (environ[i])
	{
		printf("%s\n", environ[i]);
		i++;
	}
}
