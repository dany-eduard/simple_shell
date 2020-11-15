#include <stdio.h>
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
 * main - main function
 * @promt: promt of shell
 * @line: line to read
 * @lineSize: length of line read
 * @charactersRead: char read
 * 
 * Description: program that prints all the arguments,
 * without using ac. Prints "$ ", wait for the user to
 * enter a command, prints it on the next line.
 * 
 * Return: allways 0.
 */
int main()
{
	char *promt = "$ ", *line;
	size_t lineSize = 0;
	int charactersRead = 0;

	while(1)
	{
		write(STDOUT_FILENO, promt, _strlen(promt));
		charactersRead = getline(&line, &lineSize, stdin);
		write(STDOUT_FILENO, line, charactersRead);
	}

	return (0);
}

