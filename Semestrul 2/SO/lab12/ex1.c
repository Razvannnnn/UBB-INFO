// Se dau 100.000 de numere aleatoare. Folosind un numar potrivit de thread-uri si cele mai portivite mecanisme de
// sincronizare, sa se determine cea mai mica diferenta dintre 2 numere din fiecare interval de 2000 de numere.

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <limits.h>
#include <time.h>
#include <math.h>
#include <sys/types.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <unistd.h>

#define MAX_NUM 100000
#define MAX_THR 50

int numere[MAX_NUM];
int minDif = INT_MAX;

pthread_mutex_t mtx = PTHREAD_MUTEX_INITIALIZER;

void* doDif(void* arg)
{
	int id = *(int*)arg;
	free(arg);

	int st = id * MAX_NUM/MAX_THR;
	int dr = st + MAX_NUM/MAX_THR;

	int dif = INT_MAX;
	for(int i=st;i<dr-1;i++)
	{
		for(int j=i+1;j<dr;j++)
		{
			if(dif > abs(numere[i] - numere[j]))
				dif = abs(numere[i] - numere[j]);
		}
	}
	pthread_mutex_lock(&mtx);
	if(minDif > dif)
	{
		minDif = dif;
	}
	pthread_mutex_unlock(&mtx);
	return NULL;
}

int main(int argc, char* argv[])
{
	//generare 100000 de numere aleatoare
	srand(time(0));

	//citesc 100000 de numere aleatoare
	//1.
	//for(int i=0;i<MAX_NUM;i++)
	//{
	//	numere[i] = rand();
	//}

	//2.
	int fd = open("file.bin", O_RDONLY);
	if(fd == -1)
	{
		perror("open()");
		exit(1);
	}
	for(int i=0;i<=MAX_NUM;i++)
	{
		read(fd, &numere[i], sizeof(int));
	}
	close(fd);


	pthread_t tid[MAX_THR];

	for(int i=0;i<MAX_THR;i++)
	{
		int *id = malloc(sizeof(int));
		*id = i;
		pthread_create(&tid[i], NULL, doDif, id);
	}
	for(int i=0;i<MAX_THR;i++)
	{
		pthread_join(tid[i], NULL);
	}

	printf("Diferenta minima: %d\n", minDif);
	return 0;
}
