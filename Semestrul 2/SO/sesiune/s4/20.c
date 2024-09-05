#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <wait.h>

int main(int argc, char *argv[]) {
  int p[2];
  pipe(p);

  if (fork() == 0) {
    close(p[1]); // nu scriem
    dup2(p[0], STDIN_FILENO);
    execl("/bin/pwd", "/bin/pwd", NULL);
    perror("execl");
    exit(EXIT_FAILURE);
  }
  close(p[0]);
  return EXIT_SUCCESS;
}
