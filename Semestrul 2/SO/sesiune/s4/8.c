#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <wait.h>

int main(int argc, char *argv[]) {
  char *s[3] = {"A", "B", "C"};
  for (int i = 0; i < 3; ++i) {
    execl("/bin/echo", "/bin/echo", s[i], NULL);
  }
  return EXIT_SUCCESS;
}
