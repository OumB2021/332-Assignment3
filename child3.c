#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main()
{
  execlp("date", "date", NULL);
  perror("Error in execlp for child3");
  exit(EXIT_FAILURE);
}