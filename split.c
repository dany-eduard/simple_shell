#include "sh.h"

/**
 * split - breaks the chain into segments or tokens depending
 * on the delimiters that we impose on it, each time
 * it finds one it will tokenize it.
 * @line: The pointer to the line that enters to tokenize.
 * Return: A pointer to the first token found in the string or null
 * if there are no tokens left to retrieve.
 */
char **split(char *line)
{
	char *slice;
	char **tokens;
	int position = 0;
	int buffer = 1024;

	tokens = malloc(buffer * sizeof(char *));

	if (!tokens)
	{
		fprintf(stderr, "lsh: allocation error\n");
		exit(EXIT_FAILURE);
	}

	slice = strtok(line, " \t\n\r;	");
	while (slice)
	{
		tokens[position] = slice;
		position++;
		slice = strtok(NULL, " \t\n\r;	");
	}

	tokens[position] = NULL;
	return (tokens);
}
