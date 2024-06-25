#include "main.h"
/**
	* get_file_loc - Get the executable path of file
	* @path: Full path variable
	* @file_name: The executable file
	* Return: Full path to the executable file
	*/

char *get_file_loc(char *path, char *file_name)
{
				char *path_copy, *token;
				struct stat file_path;
				char *path_buffer = NULL;

				path_copy = strdup(path);
				if (!path_copy)
				{
					perror("Error: strdup failed");
					return (NULL);
				}
				token = strtok(path_copy, ":");
				while (token)
				{
					if (path_buffer)
					{
						free(path_buffer);
						path_buffer = NULL;
					}
					path_buffer = malloc(strlen(token) + strlen(file_name) + 2);
					if (!path_buffer)
					{
						perror("Error: malloc failed");
						free(path_copy);
						exit(EXIT_FAILURE);
					}
					strcpy(path_buffer, token);
					strcat(path_buffer, "/");
					strcat(path_buffer, file_name);
					strcat(path_buffer, "\0");
					if (stat(path_buffer, &file_path) == 0 && access(path_buffer, X_OK) == 0)
					{
						free(path_copy);
						return (path_buffer); }
					token = strtok(NULL, ":");
				}
				free(path_copy);
				if (path_buffer)
					free(path_buffer);

				return (NULL);
}
