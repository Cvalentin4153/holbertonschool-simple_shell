#include "shell.h"
/**
 * tokenize_input - Tokenizes the input string into arguments
 * @line: The input string
 * @args: Array to store the tokenized arguments
 * Return: void
 */
void tokenize_input(char *line, char **args)
{
	int i = 0;

	args[i] = strtok(line, " \t");
	while (args[i] && i < 100 - 1)
	{
		i++;
		args[i] = strtok(NULL, " \t");
	}
	args[i] = NULL;
}
