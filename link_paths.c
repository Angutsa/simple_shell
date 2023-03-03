#include "main.h"

struct path *add_to_linked_list(char *variable, struct path *node);


/**
  * link_path - creates a linked list for the PATH directories
  * @env: environment variables
  * Return: returns the head node to the linked list
  */
struct path *link_path(char **env)
{
	char *variable = NULL;
	int i;
	struct path *head = NULL;

	variable = _getenv("PATH", env);
	head = add_to_linked_list(variable + 5, head);

	for (i = 5; variable[i] != '\0'; i++)
	{
		if (variable[i - 1] == '\0')
			add_to_linked_list(variable + i, head);

		if (variable[i] == ':')
			variable[i] = '\0';
	}
	return (head);
}

/**
  * add_to_linked_list - adds new directory to the linked list
  * @variable: variable to add to linked list
  * @node: head node of PATH linked list
  * Return: pointer to node added
  */
struct path *add_to_linked_list(char *variable, struct path *node)
{
	if (node == NULL)
	{
		node = malloc(sizeof(struct path));
        /* you don't check that malloc fails here */
		node->directory = variable;
		node->next = NULL;
	}
	else
	{
		node->next = add_to_linked_list(variable, node->next);
	}
	return (node);
}
