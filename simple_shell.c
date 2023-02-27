#include "main.h"

void execute_command(char *progname, char *arguments[], char **env);
void cleanup_args(char *arguments[]);
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
	char *arguments[100];
	struct path *path_head = NULL;

	tmp++; /** placeholder **/

	/** initialise path linked list **/
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
		arguments[0] = find_command(arguments[0], path_head);
		if (arguments[0] == NULL)
		{
			perror(argv[0]);
			cleanup_args(arguments);
			continue;
		}

		execute_command(argv[0], arguments, env);
	}
	cleanup_args(arguments);
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
  * cleanup_args - frees memory allocated to args internally
  * @arguments: array of pointer to the argument strings
  */
void cleanup_args(char *arguments[])
{
	int i;

	/** Frees arguments since it's pointers were realloced by getline **/
	for (i = 0; arguments[i] != NULL; i++)
	{
		free(arguments[i]);
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
