#include "main.h"

/**
	* startsWithForwardSlash - Checks if file starts with "/"
	* @str: The filename to be checked
	*
	* Return: 0 if yes and 1 if NO
	*/

int startsWithForwardSlash(const char *str)
{
				if (str != NULL || str[0] == '/')
					return (1);

				return (0);
}
