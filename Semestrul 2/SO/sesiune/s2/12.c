#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <wait.h>
#define N 10
int n = 0;
pthread_mutex_t mutex;
void *f(void *p) {
  pthread_mutex_lock(&mutex);
  n++;
  pthread_mutex_unlock(&mutex);
  return NULL;
}

int main(int argc, char *argv[]) {
  pthread_mutex_init(&mutex, NULL);
  pthread_t *th;
  th = (pthread_t *)malloc(sizeof(pthread_t) * N);

  for (int i = 0; i < N; ++i) {
    if (pthread_create(&th[i], NULL, f, NULL) != 0) {
      return EXIT_FAILURE;
    }
  }

  for (int i = 0; i < N; ++i) {
    if (pthread_join(th[i], NULL) != 0) {
      return EXIT_FAILURE;
    }
  }
  printf("%d\n", n);
  free(th);
  return EXIT_SUCCESS;
}
