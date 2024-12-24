#include "shell.h"
/**
 * main - Entry point of the simple shell program
 *
 * Description:
 * This program implements a basic shell loop. It continuously displays
 * a prompt (`sup$`), waits for user input, and handles the input. If the
 * user enters an empty line, the program will display the prompt again.
 * The shell exits gracefully when the end-of-file (Ctrl+D) condition is
 * detected.
 *
 * Return: 0 on successful execution
 */
int main(void)
{
	char *line = NULL; /*Buffer to store user input*/
	size_t len = 0; /*Size of buffer*/
	ssize_t nread; /*Number of characters read*/

	while (1)
	{
		printf("sup$ "); /*Print prompt*/
		nread = getline(&line, &len, stdin); /*Read user input*/

		if (nread == -1) /*Handle shell exit*/
		{
			printf("\nExiting shell...\n");
			free(line);
			break;
		}

		if (nread == 1) /*Handle empty input and print new line*/
		{
			continue;
		}
	}
	free(line); /*Free allocated memory*/
	return(0);
}
