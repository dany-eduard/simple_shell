#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

/**
 * _strlen - return the length of a string
 * @s: is a string
 * Return: length of s
 */
int _strlen(char *s)
{
	int i;

	for (i = 0; s[i] != '\0'; i++)
		;

	return (i);
}

/**
 * _strcmp - compares two strings
 * @s1: is a string
 * @s2: is a string
 * Return: int less 0, greater 0 o 0 if is equal
 */
int _strcmp(char *s1, char *s2)
{
	while (*s1 && *s2)
	{
		if (*s1 != *s2)
		{
			return (*s1 - *s2);
		}
		s1++;
		s2++;
	}
	if (*s1 == *s2)
		return (0);
	else
		return (*s1 > *s2 ? 1 : -1);

}

/**
 * main - main function.
 * Return: 0 if success.
 */
int main(void)
{
	char *prompt = "linux@user$ ", *line, *o = "exit\n";
	size_t len = 0;

	while (1)
	{
		write(STDOUT_FILENO, prompt, _strlen(prompt));
		if (getline(&line, &len, stdin) == EOF)
		{
			write(STDOUT_FILENO, "\n", 2);
			exit(EXIT_SUCCESS);
		}
		if (_strcmp(line, o) == 0)
		{
			printf("Exit\n");
			exit(0);
		}
		write(STDOUT_FILENO, line, _strlen(line));
	}

	return (0);
}
