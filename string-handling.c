#include "sh.h"

/**
* _strlen - Get the length of a string.
* @s: The pointer to the string.
* Return: lenght of the string.
*/
int _strlen(char *s)
{
	int i = 0;

	while (s[i] != '\0')
		i++;
	return (i);
}
