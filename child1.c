#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

int main(int argc, char *argv[])
{

  char c; // Holder for each character in text.
  int fd_source, fd_destination;

  fd_source = open(argv[1], O_RDONLY);
  if (fd_source == -1)
  {
    perror("open");
    exit(0);
  }

  // File opened for read, write and created if doesn't exist
  fd_destination = open("destination.txt", O_CREAT | O_RDWR, 0644);
  if (fd_destination == -1)
  {
    perror("open");
    exit(0);
  }

  int bytes_read; // Holds the number of bytes read from source file.
  int count = 1;  // count for loop
  // while loop reads each character in source.txt and copies it into destination.txt
  while ((bytes_read = read(fd_source, &c, sizeof(c))) > 0)
    write(fd_destination, &c, sizeof(c)); // write value to destination

  close(fd_source);      // close source file
  close(fd_destination); // close destination file
  printf("\nContent copied sucessfully from %s to %s\n", argv[1], argv[2]);

  sleep(10); // Sleep for 10 seconds

  exit(EXIT_SUCCESS);

  return 0;
}