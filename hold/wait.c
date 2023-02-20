#include "main.h"

/**
  * main - forks and waits
  * Return: Always 0
  */
int main(void)
{
	pid_t child_pid;
	int status;

	printf("Before Fork 1\n");
	child_pid = fork();
	printf("After Fork 1\n");

	printf("Before Fork 2\n");
	child_pid = fork();
	printf("Fork 2\n");

	if (child_pid == -1)
	{
		perror("Couldn't fork child: Error::");
		return (1);
	}

	if (child_pid == 0)
	{
		printf("In the child process, child_pid is 0. Now sleep for 3 seconds\n");
		sleep(3);
	}
	else
	{
		printf("Waiting for any child process to complete\n");
		wait(&status);
		printf("A Child Process has terminated\n");
	}

	return (0);
}
