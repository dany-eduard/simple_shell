#include "sh.h"

/**
* main - main function.
*
* Return: 0.
*/
int main(void)
{
	int condition = 1;
	int sign = 1;
	char *line = NULL;
	char **tokens = NULL;

	signal(SIGINT, sigint_handler);

	while (condition)
	{
		write(STDIN_FILENO, "$ ", 2);
		line = reading();
		sign = semicolon(line);
		tokens = split(line);
		condition = comparing(tokens);

		if (condition == 1 && sign == 1)
			condition = executing(tokens, line);

		free(line);
		free(tokens);
	}
	return (EXIT_SUCCESS);
}

/**
* reading - reads an entire line from stdin, storing
* the text including the newline and termination characters in a buffer
* and storing the address of the buffer in line.
* Return: The line read.
*/
char *reading(void)
{
	char *line = NULL;
	size_t buffsize = 0;
	ssize_t container = 0;

	container = getline(&line, &buffsize, stdin);

	if (container == EOF)
	{
		free(line);
		exit(STDERR_FILENO);
	}
	return (line);
}

/**
* sigint_handler - Signal Handler function.
* Prints a $ sign according to the command pressed.
* @sigint: Reset handler to catch SIGINT next time.
* Return: Nothing.
*/
void sigint_handler(int sigint)
{
	(void)sigint;

	signal(SIGINT, sigint_handler);
	write(STDOUT_FILENO, "\n$ ", 3);
	fflush(stdout);
}

/**
 * comparing - compare the built-in with the command entered and
 * call the respective function to execute a command.
 * @tokens: the tokenized line.
 * Return: the built-in function result.
 */
int comparing(char **tokens)
{
	if (tokens[0] == NULL)
		return (1);

	if (_strcmp(tokens[0], "exit") == 0)
		return (0);

	if (_strcmp(tokens[0], "env") == 0)
		_env(tokens);

	if (_strcmp(tokens[0], "cd") == 0)
		return (_cd(tokens));
	return (1);
}

/**
* executing - execute a program.
* @tokens: the tokenized line.
* @line: line read in the prompt.
* Return: 1.
*/
int executing(char **tokens, char *line)
{
	pid_t pid;
	int o, status;
	char path[8192] = "/bin", *aux = "/b", *aux2 = " /b.h";

	if (line[0] == aux[0] && line[1] == aux[1])
		_strcpy(path, line);
	else if (line[0] == aux2[0])
	{
		for (o = 0; line[o] != '\0'; o++)
		{
			if (line[o] == aux2[1])
				if (line[o - 1] == aux2[0])
					_strcpy(path, "/bin/ls");
		}
	}
	else if (line[0] == aux2[3] && line[2] == aux2[4])
		_strcpy(path, "/bin/ls");
	else
		_strcat(path, "/"), _strcat(path, line);
	pid = fork();
	if (pid == 0)
	{
		if (execve(path, tokens, environ) == -1)
		{
			errors(tokens);
			return (0);
		}
		exit(EXIT_FAILURE);
	}
	else if (pid < 0)
	{
		errors(tokens);
		return (0);
	}
	else
	{
		do { waitpid(pid, &status, WUNTRACED);
		} while (!WIFEXITED(status) && !WIFSIGNALED(status));
	}
	return (1);
}
