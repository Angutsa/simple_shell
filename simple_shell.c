#include "main.h"

#define MAX_ARGS 100

void execute_command(char *progname, const char* command, char *arguments[], char **env);
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
    /* z doesn't need to exist in this scope */
	int z, tmp = argc;
    /* same comment */
	char *arguments[MAX_ARGS];
    /* instead of setting this to null, you could just assign it directly to link_path */
	struct path *path_head = NULL;
    /* Ok, I see the problem is that you are being forced to use ISO C90 which forces you to put your declarations at the top. */
    char* command = NULL;

	tmp++; /** placeholder **/
    /* struct path *path_head = link_path(env); */
	path_head = link_path(env);

	for (;;)
	{
		if (isatty(STDIN_FILENO))
			_printf("($) ");

        /* this line should be int z = get_arguments(arguments, argv[-]) */
		z = get_arguments(arguments, argv[0]);
		if (z == -1)
		{
			if (isatty(STDIN_FILENO))
				_printf("\n");
			break;
		}
        /* z is never 2. get_arguments returns -1, 0, or 1. */
		else if (z == 1 || z == 2)
		{
			continue;
		}

		/** check if command exists **/
        /* You're not using the return value of find_command, which has the actual path to the command you need to execute */
        command = find_command(arguments[0], path_head);
		if (!command)
		{
			perror(argv[0]);
			continue;
		}
        /* arguments has the command, but not the full path to the command so it always fails */
		execute_command(argv[0], command, arguments, env);

		if (arguments[0] != NULL)
            /* You have a double free exception here because find_command free's arguments[0] */
            /* The form of your program which has functions returning malloc'd pointers is bad and leads to confusing malloc/free pairs. */
            /* It would be better to keep your mallocs and free's more coupled. */
            /* For example, your link_path/cleanup_path is a good pair. */
            /* You have get_arguments, you could create a free_arguments called here. */
            /* it's good practice for memory allocated to be free'd in the same scope so it's not hard to find leaks. */
            /* When it can't be free'd in the same scope, you should have your own allocator/free functions.
               Like how link_path allocates and cleanup_path frees) and then those functions should be called in the same scope.
               Or if not the same scope, at least the same file, somewhere nearby. */
			free(arguments[0]);
	}
	cleanup_path(path_head);
	return (0);
}

/**
  * execute_command - executes the command with the arguments passed
  * @progname: name of the program. Used in errors
  * @command: Full path to the command to execute
  * @arguments: array of user input - command and arguments
  * @env: environment variables
  */
void execute_command(char *progname, const char* command, char *arguments[], char **env)
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
		if (execve(command, arguments, env) == -1)
		{
            /* This leads to a misleading error because progname is used */
            /* When I try to execute "ls" I get "./hsh: No such file or directory" */
			/* perror(progname); */
			perror(arguments[0]);
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
/* This should go in the same file as link_path. Keep your free's and mallocs together */
void cleanup_path(struct path *node)
{
	if (node == NULL)
		return;

	cleanup_path(node->next);
	free(node);
}
