#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>

/**
  * main - prints the PID of the parent process
  * Description: Prints the same as echo $$, since it is the current process. Source -> https://unix.stackexchange.com/questions/186119/what-is-the-meaning-of-the-number-displayed-by-echo
  * Return: 0 if success
**/
int main(void) {
  	pid_t my_pid = getpid();
	pid_t parent_pid = getppid();

	printf("Child process: %u\n", my_pid);
	printf("Parent process: %u\n", parent_pid);

  	return 0;
}
