#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <wait.h>
int main(int argc, char *argv[]) {
  int r, w, n = 0;
  r = open("abc", O_RDONLY);
  n++;
  w = open("abc", O_WRONLY);
  n++;
  printf("%d\n", n);
  return EXIT_SUCCESS;
}
