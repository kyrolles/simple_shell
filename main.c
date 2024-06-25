#include "main.h"

/**
 * main - prints the environment
 * @argc: not used really.
 * @argv: also not used really.
 * Return: Always 0.
 */

int
main(int argc, char **argv)
{
	size_t n = 10;
	char *buf = NULL, *pieces = NULL, **ppieces = NULL;
	ssize_t read;
	pid_t Child_process;
	int STATE, i, Texe;
	char *path;

	(void)argc, (void)argv;

	while (1)
	{
		/*buf = malloc(sizeof(char) * n);*/
		write(STDOUT_FILENO, "kyrl$ ", 6);
		read = getline(&buf, &n, stdin);

		if (read == -1)
		{
			perror("Exiting shell");
			free(buf);
			exit(0);
		}

		ppieces = malloc(sizeof(char *) * 1024);
		if (ppieces == NULL)
		{
			perror("Failed to allocate memory for ppieces");
			free(buf);
			exit(1);
		}

		pieces = strtok(buf, " \n");
		i = 0;
		while (pieces != NULL)
		{
			ppieces[i] = pieces;
			pieces = strtok(NULL, " \n");
			i++;
		}
		ppieces[i] = NULL;
		Child_process = fork();
		if (Child_process == -1)
		{
			perror("faild to make child process!\n");
			exit(1);
		}
		if (Child_process == 0)
		{
			path = get_file_path(ppieces[0]);
			if (path == NULL)
			{
				perror("Failed to get file path");
				free(ppieces);
				free(buf);
				exit(1);
			}
			Texe = execve(path, ppieces, __environ);

			if (Texe == -1)
			{
				perror("faild to execute");
				free(ppieces);
				free(buf);
				free(path);
				exit(1);
			}
		}
		else
			{
				wait(&STATE);
				free(path);
			}
		free(ppieces);
	}
	free(buf);
	free(path);
	return (0);
}
