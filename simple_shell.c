#include "main.h"

#define MAX_ARGS 100

void execute_command(char *progname, char *arguments[], char **env);
void cleanup_path(struct path *node);

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
	char *arguments[MAX_ARGS];
	struct path *path_head = NULL;

	tmp++; /** placeholder **/
	path_head = link_path(env);

	for (;;)
	{
		if (isatty(STDIN_FILENO))
			_printf("($) ");

		z = get_arguments(arguments, argv[0]);
		if (z == -1)
		{
			if (isatty(STDIN_FILENO))
				_printf("\n");
			break;
		}
		else if (z == 1 || z == 2)
		{
			continue;
		}

		/** check if command exists **/
		if (find_command(arguments[0], path_head) == NULL)
		{
			perror(argv[0]);
			continue;
		}
		execute_command(argv[0], arguments, env);

		if (arguments[0] != NULL)
			free(arguments[0]);
	}
	cleanup_path(path_head);
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

/**
  * cleanup_path - frees all memory allocated for the PATH list
  * @node: head node
  */
void cleanup_path(struct path *node)
{
	if (node == NULL)
		return;

	cleanup_path(node->next);
	free(node);
}
