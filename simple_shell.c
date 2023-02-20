#include "main.h"

/**
  * main - program mimics a simple shell
  * Return: 0 on sucess else -1
  */
int main(int argc, char **argv, char **env)
{
	size_t x = 0;
	int n = 0, words = 0, i = 0, status;
	char *input = NULL, *delim = " ";
	char *arguments[64];
	int tmp;
	pid_t mypid;

	for(;;)
	{
		input = get_user_input();
		if (input[0] == '\0')
			continue;

		/* TODO: Handle EOF */
	
		get_arguments(arguments, input);
		
		/* Execute command in a child process */
		mypid = fork();
		if(mypid == -1)
		{
			perror("./hsh");
			return (-1);
		}

		if (mypid == 0)
		{
			if(execve(arguments[0], arguments, NULL) == -1)
			{
				perror("./hsh");
			}
		}
		else
		{
			wait(&status);
		}
	}

	free(input);
	return (0);
}
