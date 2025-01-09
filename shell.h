#ifndef HEADER
#define HEADER

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
#include <errno.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <dirent.h>

void exit_shell(void);
int change_directory(char **args);
void print_env(void);
void execute_command(char **args);

#endif
