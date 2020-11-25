#include "sh.h"

/**
* errors - error handling.
* @tokens: error case.
*/
void errors(char __attribute__((unused)) **tokens)
{
	if (tokens[0])
	{
		write(STDOUT_FILENO, "hsh", 3);
		write(STDOUT_FILENO, ": ", 2);
		write(STDOUT_FILENO, "1", 1);
		write(STDOUT_FILENO, ": ", 2);
		write(STDOUT_FILENO, ": ", 2);
		write(STDOUT_FILENO, "not found", _strlen("not found"));
		write(STDOUT_FILENO, "\n", _strlen("\n"));
	}
}

/**
* semicolon - handle the commands separator (;).
* @line: a pointer to the stdin line entered.
* Return: 0.
*/
int semicolon(char *line)
{
	char *one_token, **total, **tokens;
	int buffer = 1024, status = 1, i = 0, j = 0;

	total = malloc(buffer * sizeof(char *));

	if (!total)
		exit(EXIT_FAILURE);

	one_token = strtok(line, ";");
	while (one_token)
	{
		total[i] = one_token;
		i++;
		one_token = strtok(NULL, ";");
	}
	total[i] = NULL;
	if (total[1] == NULL)
	{
		free(total);
		return (1);
	}
	else
	{
		while (total[j])
		{
			tokens = split(total[j]);
			status = comparing(tokens);

			if (status == 1)
			status = executing(tokens, line);
			j++;
			free(tokens);
		}
	}
	free(total);
	return (0);
}
