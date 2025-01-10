#include "shell.h"
/**
 * sanitize_input - Removes leading/trailing whitespace
 * @input: Raw input string
 *
 * Return: Pointer to the sanitized string, or NULL if empty
 */
char *sanitize_input(char *input)
{
	char *end;

	while (*input == ' ' || *input == '\t')
		input++;

	if (*input == '\0')
		return (NULL);

	end = input + strlen(input) - 1;
	while (end > input && (*end == ' ' || *end == '\t'))
		end--;

	*(end + 1) = '\0';
	return (input);
}
