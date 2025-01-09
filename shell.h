#ifndef SHELL_H
#define SHELL_H

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
#include <errno.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <dirent.h>

extern char **environ;
extern int last_status;

char *get_env(const char *name);
void exit_shell(void);
int change_directory(char **args);
void print_env(void);
int execute_command(char **args);
char *find_command(char *command);

#endif
