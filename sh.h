#ifndef _SHELL_H_
#define _SHELL_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>

int main(void);
char *reading(void);
char **split(char *line);
int executing(char **tokens, char *line);
int comparing(char **tokens);
void sigint_handler(int sigint);
int semicolon(char *line);

void _env(char **commands);
int _cd(char **args);

void errors(char __attribute__((unused)) **tokens);
int _strlen(char *s);
int _strcmp(char *s1, char *s2);
char *_strcat(char *dest, char *src);
char *_strcpy(char *dest, char *src);
extern char **environ;
#endif
