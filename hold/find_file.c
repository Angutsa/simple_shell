#include "main.h"

/**
  * main - looks for files in the current path
  * Return: 0 on success, -1 otherwise
  */
int main(int argc, char **argv)
{
	int i = 0, s = 0;
	char *file;
	struct stat statbuf;

	if (argc < 2)
	{
		printf("Usage: %s _filename_\n", argv[0]);
		return (-1);
	}

	for (i = 1; i < argc; i++)
	{
		file = argv[i];
		printf("%s: ", file);

		s = stat(file, &statbuf);
		if (s == 0)
			printf("FOUND\n");
		else
			printf("NOT FOUND\n");
	}
	return (0);
}
