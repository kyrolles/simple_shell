#include "main.h"
#define PROMPT "kyrl$ "
#define PROMPT_SIZE 7

/**
 *
 * main - prints the environment
 * @ac: not used really.
 * @av: also not used really.
 * Return: Always 0.
 */

int main(int ac, char **av)
{
    (void)ac;
    (void)av;
    size_t n = 0;
    char *buf = NULL, *pieces = NULL, **ppieces = NULL;
    ssize_t read;
    pid_t child_process;
    int state, i;

    while (1)
    {
        write(STDOUT_FILENO, PROMPT, PROMPT_SIZE);
        read = getline(&buf, &n, stdin);

        if (read == -1)
        {
            perror("Exiting shell");
            break;
        }

        if (!ppieces)
        {
            perror("malloc failed");
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

        child_process = fork();
        if (child_process == -1)
        {
            perror("Failed to create child process");
            free(ppieces);
            free(buf);
            exit(1);
        }
        if (child_process == 0)
        {
            if (execve(ppieces[0], ppieces, NULL) == -1)
            {
                perror("Failed to execute command");
                free(ppieces);
                free(buf);
                exit(1);
            }
        }
        else
        {
            wait(&state);
        }

        free(ppieces);
    }
    free(buf);
    return 0;
}
