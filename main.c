#include "main.h"

/**
 * main - prints the environment
 * @ac: not used really.
 * @av: also not used really.
 * Return: Always 0.
 */

int
main(int ac, char **av)
{

	(void)ac, (void)av;
	size_t n = 10;
	char *buf = NULL, *pieces = NULL, **ppieces = NULL;
	ssize_t read;
	pid_t Child_process;
	int STATE, i, Texe;

	while (1)
	{
		buf = malloc(sizeof(char) * n);
		write(STDOUT_FILENO, "kyrl$ ", 7);
		read = getline(&buf, &n, stdin);

		if (read == -1)
		{
			perror("Exiting shell");
			exit(1);
		}

		ppieces = malloc(sizeof(char) * 1024);

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
			Texe = execve(ppieces[0], ppieces, NULL);

			if (Texe == -1)
			{
				perror("faild to execute");
				exit(1);
			}
		}
		else
			{
				wait(&STATE);
			}
		free(ppieces);
	}
	free(buf);
	return (0);
}
