#include "shell.h"
/**
 * get_env - Retrieves the value of an environment variable
 * @environ: Environment variables
 * @name: Name of the variable
 * Return: Value of the variable, or NULL if not found
 */
char *get_env(char **environ, const char *name)
{
	int i = 0;
	size_t name_len = strlen(name);

	while (environ[i])
	{
		if (strncmp(environ[i], name, name_len) == 0 && environ[i][name_len] == '=')
			return (environ[i] + name_len + 1);
		i++;
	}
	return (NULL);
}
