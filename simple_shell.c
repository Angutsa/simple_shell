#include "main.h"

void execute_command(char *progname, char *arguments[], char **env);

/**
  * main - program mimics a simple shell
  * @argc: argument count
  * @argv: argument vector
  * @env: environment variables
  * Return: 0 on success else -1
  */
int main(int argc, char **argv, char **env)
{
	int z, tmp = argc;
	char *input = "", *arguments[100];
	struct path *path_head = NULL;

	tmp++; /** placeholder **/

	/** initialise path linked list **/
	path_head = link_path(env);

	for (;;)
	{
		_printf("($) ");
		z = get_arguments(arguments, input, argv[0]);
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

		/** check if command exists **/
		arguments[0] = find_command(arguments[0], path_head);
		if (arguments[0] == NULL)
		{
			perror(argv[0]);
			continue;
		}

		execute_command(argv[0], arguments, env);
	}
	return (0);
}

/**
  * execute_command - executes the command with the arguments passed
  * @progname: name of the program. Used in errors
  * @arguments: array of user input - command and arguments
  * @env: environment variables
  */
void execute_command(char *progname, char *arguments[], char **env)
{
	pid_t mypid;
	int status;

	mypid = fork();
	if (mypid == -1)
	{
		perror(progname);
		exit(EXIT_FAILURE);
	}

	if (mypid == 0)
	{
		if (execve(arguments[0], arguments, env) == -1)
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
