#include "main.h"

/**
  * get_file_path - Get's the full path of the file
  * @file_name: Argument name
  *
  * Return: The full path argument to the file
  */

char *get_file_path(char *file_name)
{

        char *path = getenv("PATH");
				char *Full_Path;

				if (file_name == NULL)
				{
						perror("File name is NULL");
						return NULL;
				}
				
				if (startsWithForwardSlash(file_name) && access(file_name, X_OK) == 0)
							return (strdup(file_name));

        
				if (!path)
        {
                perror("Path not found");
                return (NULL);
        }

				Full_Path = get_file_loc(path, file_name);

				if(Full_Path == NULL)
				{
							perror("absolute path not found");
							return(NULL);
				}

        return (Full_Path);
}
