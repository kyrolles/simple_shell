#include "main.h"

/**
 * _strcpy - fuction copies the string pointed
 * @dest: pointer to copy the string to.
 * @src: the string to copy to the destination.
 *
 * Return: a copy of the src.
 */
char *_strcpy(char *dest, char *src)
{
	int index = -1;

do {
index++;
dest[index] = *(src + index);
} while (*(src + index) != '\0');
	return (dest);
}

