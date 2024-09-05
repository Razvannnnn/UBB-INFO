#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>
#include <wait.h>

void f(int n) {
  if (n > 0 && fork() == 0) {
    printf("%d\n", getpid());
    f(n - 1);
    wait(NULL);
  } else {
    printf("%d\n", getpid());
    wait(NULL);
  }
}

int main(int argc, char *argv[]) {
  f(3);
  return EXIT_SUCCESS;
}
