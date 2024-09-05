#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#include <time.h>

#define MAX_THR 100
#define MAX_NUM 100000

pthread_mutex_t mtx = PTHREAD_MUTEX_INITIALIZER;
int suma;
int numere[MAX_NUM];

void* do_work(void* arg) {
	int id = *(int*)arg;

	int st = id * MAX_NUM/MAX_THR;
	int dr = st + MAX_NUM/MAX_THR;

	for(int i=st;i<dr;i++) {
		pthread_mutex_lock(&mtx);
		suma=suma+numere[i];
		pthread_mutex_unlock(&mtx);
	}
	return NULL;
}

int main(int argc, char* argv[])
{
	pthread_t tid[MAX_THR];

	srand(time(NULL));

	for(int i=0;i<MAX_NUM;i++) {
		numere[i] = rand() % 100;
	}

	for(int i=0;i<MAX_THR;i++) {
		int* id = malloc(sizeof(int));
		*id = i;
		pthread_create(&tid[i], NULL, do_work, id);
	}

	for(int i=0;i<MAX_THR;i++) {
		pthread_join(tid[i], NULL);
	}

	printf("Suma: %d\n",suma);

	return 0;
}
