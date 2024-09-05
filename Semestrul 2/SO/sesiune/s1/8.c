#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <wait.h>

int main(int argc, char *argv[]) {
  char *s[3] = {"A", "B", "C"};
  for (int i = 0; i < 3; ++i) {
    pid_t pid = fork();
    if (pid != 0) { // Adica daca e parinte afiseaza
      execl("/bin/echo", "/bin/echo", s[i], NULL);
    }
    printf("Parinte : %d , Copil : %d\n", getppid(), getpid());
  }
  return EXIT_SUCCESS;
}
