#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <pthread.h>
#include <limits.h>
#include <math.h>

int n, v[90001], fr[10], suma, minim = INT_MAX;
int avg;
pthread_t citire, tid[10];
pthread_barrier_t barr;
pthread_mutex_t mtx = PTHREAD_MUTEX_INITIALIZER;

void* do_work(void* arg)
{
	int id = *(int*)arg;
	for(int i=0;i<n;i++)
	{
		fr[v[i]%10]++;
	}

	pthread_mutex_lock(&mtx);
	suma=suma+fr[id];
	pthread_mutex_unlock(&mtx);

	pthread_barrier_wait(&barr);

	avg = suma/10;

	pthread_mutex_lock(&mtx);
	if(abs(avg-fr[id]) < minim) minim = abs(avg-fr[id]);
	pthread_mutex_unlock(&mtx);

	free(arg);

	return NULL;
}

void* cititor(void* arg)
{
	FILE* fd = fopen("file", "r");
	if(fd == NULL)
	{
		printf("Eroare fisier");
		exit(1);
	}
	for(int i=0;i<n;i++)
	{
		fscanf(fd,"%d",&v[i]);
	}
	fclose(fd);

	return NULL;
}

int main(int argc, char* argv[])
{
	printf("Numar natural N:");
	scanf("%d", &n);

	pthread_create(&citire, NULL, cititor, NULL);
	pthread_join(citire, NULL);
	pthread_barrier_init(&barr, NULL, 10);

	for(int i=0;i<=9;i++)
	{
		int* id = (int*)malloc(sizeof(int));
		*id = i;
		pthread_create(&tid[i], NULL, do_work, id);
	}

	for(int i=0;i<=9;i++)
	{
		pthread_join(tid[i],NULL);
	}

	for(int i=0;i<=9;i++)
	{
		if(avg-fr[i] == minim) printf("NR: %d - %d", i, fr[i]);
	}

	pthread_barrier_destroy(&barr);

	return 0;
}
