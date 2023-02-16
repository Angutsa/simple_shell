#include <stdio.h>
#include <unistd.h>

/**
  * fork_wait_exec - forks, waits then executes
  * Description: fork_wait_exec() will create a child process then wait
  * for it to exit before creating a new child process
  */
void fork_wait_exec()
{
	/* TODO: still work in progress */
	pid_t my_pid;
        pid_t pid;

	printf("Before fork\n");
	pid = fork();
	if (pid == -1)
	{
	       perror("Error:");
	       return;
	}
	printf("After fork\n");
	my_pid = getpid();
	printf("My pid is %u\n", my_pid);
}
