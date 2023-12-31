// parent.c
#define GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>

int main(int argc, char *argv[])
{
  pid_t pid; /* process id */

  for (int i = 0; i < 3; ++i)
  {
    pid = fork();

    // check for errors in the creation of the process
    if (pid == -1)
    {
      perror("Process creation failed");
      exit(EXIT_FAILURE);
    }

    else if (pid == 0)
    {
      // Child process
      switch (i)
      {

      // Child process 1
      case 0:
        execl("./child1", "child1", argv[1], argv[2], NULL);
        perror("Error in execl for child1");
        exit(EXIT_FAILURE);

      // Child process 2
      case 1:
        execl("./child2", "child2", argv[3], NULL);
        perror("Error in execl for child2");
        exit(EXIT_FAILURE);

      // Child process 3
      case 2:
        execlp("./child3", "child3", NULL);
        perror("Error in execlp for child3");
        exit(EXIT_FAILURE);
      }
    }
  }

  // Wait for all child processes to complete
  for (int i = 0; i < 3; ++i)
  {
    wait(NULL);
  }
}
