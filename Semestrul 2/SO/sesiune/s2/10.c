#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <wait.h>

int main(int argc, char *argv[]) {
  int p[2];
  char buf[10] = "abcdefghij";
  int n;
  pipe(p);

  n = read(p[0], buf, 10);
  printf("%d\n", n);
  return EXIT_SUCCESS;
}
