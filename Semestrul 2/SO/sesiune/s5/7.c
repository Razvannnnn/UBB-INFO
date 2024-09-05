#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <wait.h>
int main(int argc, char *argv[]) {
  for (int i = 0; i < 3; ++i) {
    fork();
    execlp("ls", "ls", "/", NULL);
  }
  return EXIT_SUCCESS;
}
