#include "sh.h"

/**
 * _env - prints the environments variables.
 * @commands: commands read.
 * return: Nothing.
 */
void _env(char **commands)
{
	int i;
	char *s = *environ;

	if (commands[1] != NULL)
		return;

	for (i = 0; s; i++)
	{
		write(STDIN_FILENO, s, _strlen(s));
		write(STDIN_FILENO, "\n", 1);
		s = *(environ + i);
	}
}

/**
 * _cd - change of directories in this Shell.
 * @args: The number of arguments for cd.
 * Return: Always 2, to continue executing.
 */
int _cd(char **args)
{
	if (args[1] == NULL)
		return (STDERR_FILENO);
	if (chdir(args[1]) != 0)
		errors(args);

	return (STDERR_FILENO);
}
