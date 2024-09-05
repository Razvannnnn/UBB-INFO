#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#include <time.h>
#include <limits.h>

#define MAX_THR 100

int n, suma;
int numere[100001];
int fr[100];
int min=INT_MAX;
double M;

pthread_mutex_t mtx = PTHREAD_MUTEX_INITIALIZER;
pthread_barrier_t barr;

void* do_work(void* arg)
{
	int id = *(int*)arg;
	free(arg);

	for(int i=0;i<n;i++)
	{
		fr[id]++;
	}

	pthread_mutex_lock(&mtx);
	suma = suma+id*fr[id];
	pthread_mutex_unlock(&mtx);

	pthread_barrier_wait(&barr);

	M=suma/25;

	pthread_mutex_lock(&mtx);
	if(min>abs(M-fr[id])) min = abs(M-fr[id]);
	pthread_mutex_unlock(&mtx);

	pthread_barrier_wait(&barr);

	if(abs(M-fr[id]) == min) {
		printf("Nr prim:%d, frecv:%d\n", id, min);
	}

	return NULL;
}

int prim(int x) {
	if(x<=1) return 0;
	if(x==2) return 1;
	if(x%2==0) return 0;
	for(int i=3;i<x/2;i=i+2) {
		if(x%i==0) return 0;
	}
	return 1;
}

int main(int argc, char* argv[])
{
	printf("Numarul natural n:");
	scanf("%d", &n);
	FILE* fd = fopen("file", "r");
	if(fd == NULL)
	{
		perror("Nu s-a reusit deschiderea fisierului");
		return -1;
	}
	for(int i=0;i<n;i++)
	{
		fscanf(fd, "%d", &numere[i]);
	}
	fclose(fd);

	pthread_barrier_init(&barr, NULL, 25);

	pthread_t tid[MAX_THR];
	int cnt = 0;

	for(int i=0;i<MAX_THR;i++) {
		int* id = (int*)malloc(sizeof(int));
		*id = i;
		if(prim(i)) pthread_create(&tid[cnt++], NULL, do_work, id);
	}

	for(int i=0;i<cnt;i++) {
		pthread_join(tid[i], NULL);
	}

	pthread_barrier_destroy(&barr);
	pthread_mutex_destroy(&mtx);

	return 0;
}
