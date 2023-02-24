#include "main.h"

/**
  * main - executes 'ls -l /tmp' in 5 different processes
  * Return: Always 0
  */
int main(void)
{
	char *argv[] = {"/bin/ls", "-l", "/tmp", NULL};
	pid_t my_pid;
	int status;

	for (int i = 0; i < 5; i++)
	{
		printf("Loop %d\n", i);
		my_pid = fork();
		if(my_pid == -1)
		{
			perror("Error:");
			return (0);
		}

		if (my_pid == 0)
		{
			printf("---In child! Executing command!---\n\n");
			if(execve(argv[0], argv, NULL) == -1)
			perror("Error:");

		}
		else
		{
			wait(&status);
			printf("----In parent! Next child!-----\n\n");
		}
	}
	return (0);
}
