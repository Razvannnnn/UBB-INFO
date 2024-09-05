#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>
#include "header.h"

int main (int argc, char *argv[]) {
  if (0 > mkfifo(myfifo1, 0600)) {
    perror("Error on make fifo 1");
    exit(1);
  }
  if (0 > mkfifo(myfifo2, 0600)) {
    perror("Error on make fifo 2");
    exit(1);
  }
  int fd_write = open(myfifo1, O_WRONLY);
  if(-1 == fd_write) {
    perror("Error opening fifo 1 in A");
    exit(1);
  }
  int fd_read = open(myfifo2, O_RDONLY);
  if(-1 == fd_read) {
    perror("Error opening fifo 2 in A");
    close(fd_write);
    exit(1);
  }
  srandom(getpid());
  int nr = 0;
  while(nr != 10) {
    nr = random() % 10 + 1;
    if(0 > write(fd_write, &nr, sizeof(int))) {
      perror("Error on write to child");
      break;
    }
    printf("Parent sends: %d\n", nr);
    if(0 > read(fd_read, &nr, sizeof(int))) {
      perror("Error on read from child");
      break;
    }
    printf("Parent received: %d\n", nr);
  }
  close(fd_write);
  close(fd_read);
  if(0 > unlink(myfifo1)) {
    perror("Error removing fifo 1");
  }
  if(0 > unlink(myfifo2)) {
    perror("Error removing fifo 2");
  }
  return 0;
}
