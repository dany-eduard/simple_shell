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
