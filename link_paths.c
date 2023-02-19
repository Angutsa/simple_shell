#include "main.h"

/**
  * struct path - linked list for all directories in the PATH variable
  * @directory: directory in path
  * @next: pointer to next directory
  */
struct path
{
	char *directory;
	struct path *next;
};

struct path *add_to_linked_list(char *variable, struct path *node);

/**
  * main - prints directories in PATH
  * @TODO:
  * Return: TODO
  */
int main(int argc, char **argv, char **env)
{
	char *variable = NULL;
	int i;
	struct path *head = NULL;

	variable = _getenv("PATH");
	head = add_to_linked_list(variable + 5, head);

	for (i = 5; variable[i] != '\0'; i++)
	{
		if (variable[i - 1] == '\0')
			add_to_linked_list(variable + i, head);

		if (variable[i] == ':')
			variable[i] = '\0';
	}
	return (0);
}

/**
  * add_to_linked_list - adds new directory to the linked list
  * @directory: pointer to the directory name
  * @head: pointer to the head of the list
  */
struct path *add_to_linked_list(char *variable, struct path *node)
{
	if (node == NULL)
	{
		node = malloc(sizeof(struct path));
		node->directory = variable;
		node->next = NULL;
	}
	else
	{
		node->next = add_to_linked_list(variable, node->next);
	}
	return (node);
}
