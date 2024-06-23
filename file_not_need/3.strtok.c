#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int
main (int ac __attribute__ ((unused)), char **av __attribute__ ((unused)))
{
  size_t n = 10;
  char *peice;

  char *buf = malloc (sizeof (char) * n);
  printf ("type here $ ");
  getline (&buf, &n, stdin);

  peice = strtok (buf, " ");

  while (peice != NULL)
    {

      printf ("%s\n", peice);
      peice = strtok (NULL, " "
                            "-");
    }

  free (buf);
  return (0);
}
