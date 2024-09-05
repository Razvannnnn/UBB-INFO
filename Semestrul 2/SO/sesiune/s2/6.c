#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <wait.h>

int main(int argc, char *argv[]) {
  pid_t pid1 = fork();
  printf("%d\n", getpid());
  pid_t pid2 = fork();
  printf("%d\n", getpid());
  if (pid1 || pid2) {
    pid_t pid3 = fork();
    printf("%d\n", getpid());
  }
  return EXIT_SUCCESS;
}
