# Simple Shell

## Description
This repository contains a simple UNIX command interpreter (shell) written in C. The shell provides a user interface that allows users to type commands, which the shell executes. It supports basic features such as executing programs in the PATH, handling built-in commands, and handling user input in both interactive and non-interactive modes.

## Features
1. **Interactive and Non-Interactive Modes**  
   - **Interactive**: Displays a prompt (`$`) and waits for commands.
   - **Non-Interactive**: Processes commands from standard input (e.g., piped from a file).

2. **Command Execution**  
   - Searches for commands in the directories specified by the `PATH` environment variable.
   - Executes external commands via `execve`.
   - Allows full path execution (e.g., `/bin/ls`).

3. **Built-in Commands**
   - `env`: Prints the current environment variables.
   - `exit`: Exits the shell.

4. **Input Handling and Tokenization**
   - Trims leading and trailing spaces.
   - Splits input into tokens based on whitespace.

5. **Environment Handling**
   - Uses the global environment variables passed to `main`.
   - Supports commands even if `PATH` is modified or set to an empty string (with the appropriate behavior).

## Compilation
Use `gcc` with the specified flags:
```bash
gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o hsh

## Author
Carlos Valentin
[GitHub Profile](https://github.com/Cvalentin4153) | [LinkedIn](www.linkedin.com/in/carlos-valentin-24706b336)
