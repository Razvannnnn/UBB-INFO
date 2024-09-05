#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <wait.h>

int n = 0;
pthread_mutex_t m[3];
void *f(void *p) {
  int id = *(int *)p;
  pthread_mutex_lock(&m[id]);
  // id = 0 -> n = 1
  // id = 1 -> n = 3
  // id = 2 -> n = 3
  n += id;

  if (id == 0)
    n = 1;
  else if (id == 1)
    n = 3;
  else if (id == 2)
    n = 3;

  printf("%d ", n);
  pthread_mutex_unlock(&m[(id + 1) % 3]);
  // pthread_mutex_lock(&m[id]);
  free(p);
  return NULL;
}

int main(int argc, char *argv[]) {
  pthread_t t[3];
  for (int i = 0; i < 3; ++i) {
    pthread_mutex_init(&m[i], NULL);
  }
  for (int i = 0; i < 3; ++i) {
    int *nr = (int *)malloc(sizeof(int));
    *nr = i;
    pthread_create(&t[i], NULL, f, (void *)nr);
  }
  for (int i = 0; i < 3; ++i) {
    pthread_join(t[i], NULL);
  }
  for (int i = 0; i < 3; ++i) {
    pthread_mutex_destroy(&m[i]);
  }
}
