#include "main.h"

/**
  * start_simple_shell - starts the simple shell program using execve
  * TODO: Correctly link it to start a new process for shell
  */
void start_simple_shell()
{
	char *argv[] = {"./test1", "hello there", NULL};

	printf("Before execve\n");
	if (execve(argv[0], argv, NULL) == -1)
	{
		perror("Error:");
	}
	printf("After execv\n");
}
