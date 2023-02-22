#include "main.h"

/**
  * main - program mimics a simple shell
  * argc: argument count
  * argv: argument vector
  * env: environment variables
  * Return: 0 on success else -1
  */
int main(int argc, char **argv)
{
	int z, status, tmp = argc;
	char *input = "", *arguments[64], *progname = argv[0];
	pid_t mypid;

	for (;;)
	{
		_printf("($) ");
		z = get_arguments(arguments, input, progname);
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
			perror(progname);
			return (-1);
		}

		if (mypid == 0)
		{
			if (execve(arguments[0], arguments, NULL) == -1)
			{
				perror(progname);
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
