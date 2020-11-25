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

/**
* _strcmp - compare two strings.
* @s1: The pointer to the first string.
* @s2: The pointer to the second string.
* Return: return values that are as follows
* if Return value < 0 then it indicates str1 is less than str2
* if Return value > 0 then it indicates str2 is less than str1
* if Return value = 0 then it indicates str1 is equal to str2.
*/
int _strcmp(char *s1, char *s2)
{
	char c1, c2;

	do {
		c1 = *s1++;
		c2 = *s2++;

		if (c1 == '\0')
		{
			return (c1 - c2);
		}
	} while (c1 == c2);

	return (c1 - c2);
}
