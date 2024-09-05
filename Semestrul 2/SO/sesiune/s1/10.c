#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <wait.h>
int main(int argc, char *argv[]) {
  int w, n, k = 10;
  int r = open("abc", O_WRONLY);
  n = write(r, &k, sizeof(int));
  printf("%d\n", n);
  return EXIT_SUCCESS;
}
