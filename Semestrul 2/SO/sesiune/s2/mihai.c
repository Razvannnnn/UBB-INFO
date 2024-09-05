#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>
#include <wait.h>

int main(int argc, char *argv[]) {
  pid_t pid1 = fork();
  printf("%d\n", getpid());
  wait(NULL);

  pid_t pid2 = fork();
  printf("%d\n", getpid());
  wait(NULL);

  pid_t pid3 = fork();
  printf("%d\n", getpid());
  wait(NULL);

  return EXIT_SUCCESS;
}
