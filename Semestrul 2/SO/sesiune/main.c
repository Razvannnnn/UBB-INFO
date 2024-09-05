#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
  for (int i = 0; i < 3; ++i) {
    if (execlp("ls", "ls", "/", NULL) != -1)
      fork();
  }
  return EXIT_SUCCESS;
}
