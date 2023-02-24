#include "main.h"

/**
  * main - program mimics a simple shell
  * argc: argument count
  * argv: argument vector
  * env: environment variables
  * Return: 0 on success else -1
  */
int main(void)
{
	int z, status;
	char *input = "", *arguments[64];
	pid_t mypid;

	for (;;)
	{
		_printf("cisfun$ ");
		z = get_arguments(arguments, input);
		if (z == -1)
		{
			_printf("\n");
			break;
		}
		else if (z == 2 || z == 1)
		{
			continue;
		}
		input = "";

		mypid = fork();
		if (mypid == -1)
		{
			perror("./hsh");
			return (-1);
		}

		if (mypid == 0)
		{
			if (execve(arguments[0], arguments, NULL) == -1)
			{
				perror("./hsh");
				exit(EXIT_FAILURE);
			}
		}
		else
		{
			wait(&status);
		}
	}
	return (0);
}
