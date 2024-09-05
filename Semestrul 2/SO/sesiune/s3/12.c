#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <wait.h>

pthread_mutex_t a, b;
int n = 0;
void *fa(void *p) {
  pthread_mutex_lock(&a);
  ++n;
  pthread_mutex_unlock(&a);
}
void *fb(void *p) {
  pthread_mutex_lock(&b);
  ++n;
  pthread_mutex_unlock(&b);
}

int main(int argc, char *argv[]) {
  pthread_mutex_init(&a, NULL);
  pthread_mutex_init(&b, NULL);

  pthread_t *th;
  th = (pthread_t *)malloc(sizeof(pthread_t) * 2);

  pthread_create(&th[0], NULL, fa, NULL);
  pthread_create(&th[1], NULL, fb, NULL);

  pthread_join(th[0], NULL);
  pthread_join(th[1], NULL);

  pthread_mutex_destroy(&a);
  pthread_mutex_destroy(&b);

  printf("%d\n", n);

  return EXIT_SUCCESS;
}
