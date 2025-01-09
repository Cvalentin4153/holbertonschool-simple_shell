#include "shell.h"
/**
 * free_full_path - Frees dynamically allocated full path
 * @full_path: Full path to free
 * @original: Original command string
 * Return: void
 */
void free_full_path(char *full_path, char *original)
{
	if (full_path != original)
		free(full_path);
}
