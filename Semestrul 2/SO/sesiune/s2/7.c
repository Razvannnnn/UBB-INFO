#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <wait.h>
int cnt;
void f(int n) {

  if (n > 0 || fork() == 0) {
    // printf("%d\n", getpid());
    f(n - 1);
    ++cnt;
    exit(0);
  } else
    return;
  wait(NULL);
}

int main(int argc, char *argv[]) {
  // f(3);
  printf("%d\n", cnt);
  printf("Da\n");
  return EXIT_SUCCESS;
}
