#include "main.h"

/**
  * main - program mimics a super simple shell
  * Description: a first version of a super simple shell that can
  * run commands with their full path, without any argument
  * Return: 0 on sucess else -1
  */
int main(void)
{
	size_t x = 0;
	int n = 0, words = 0, i = 0, status;
	char *input = NULL, *delim = " ";
	char *arguments[64];
	pid_t mypid;

	for(;;)
	{
		/* Get user input */
		input = malloc(sizeof(char) * x);
		if (input == NULL)
		{
			perror("Error!");
			return (-1);
		}

		printf("#cisfun$ ");

		n = getline(&input, &x, stdin);
		if (n == -1)
		{
			perror("Error!");
			return (-1);
		}
	
		/* Strip newline character */
		if (input[n - 1] == '\n')
			input[n - 1] = '\0';

		n = 0;

		/* Separate input into command line arguments */
		arguments[0] = strtok(input, delim);
		if(*(arguments[0]) == '\n')
		{
			printf("Error: Wrong command entry. Try again!");
			return (0);
		}
		i++;

		for(;;)
		{
			arguments[i] = strtok(NULL, delim);
			if (arguments[i] == NULL)
				break;
			i++;
		}

		/* Execute command in a child process */
		mypid = fork();
		if(mypid == -1)
		{
			perror("Fork Error!");
			return (-1);
		}

		if (mypid == 0)
		{
			if(execve(arguments[0], arguments, NULL) == -1)
				perror("Error:");
		}
		else
		{
			wait(&status);
		}
	}

	free(input);
	return (0);
}
