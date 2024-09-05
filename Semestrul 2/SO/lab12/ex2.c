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

#define MAX_SIZE 100
#define MAX_THR 10

int buffer[100];
int fd;
int flag=0; // O - BUFFER GOL        1 - BUFFER PLIN
int sum = 0;


pthread_mutex_t mtx = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t cond = PTHREAD_COND_INITIALIZER;


void* consume(void* arg)
{
	int id = *(int*)arg;
	free(arg);

	pthread_mutex_lock(&mtx);
	while(flag == 0)
	{
		printf("[Consumator %2d] astept...\n", id);
		pthread_cond_wait(&cond, &mtx);
	}

	printf("[Consumator %2d] am inceput consumul\n", id);
	for(int i=0;i<MAX_SIZE;i++)
	{
		sum += buffer[i];
	}
	flag = 0;

	pthread_cond_signal(&cond);

	pthread_mutex_unlock(&mtx);
	return NULL;
}

void* produce(void* arg)
{
	int id = *(int*)arg;
	free(arg);

	pthread_mutex_lock(&mtx);
	while(flag == 1)
	{
		printf("[Producator %2d] astept...\n", id);
		pthread_cond_wait(&cond, &mtx);
	}
	printf("[Producator %2d] am inceput productia\n", id);
	for(int i=0;i<MAX_SIZE;i++)
	{
		read(fd, buffer[i], 2);
	}
	flag = 1;

	pthread_cond_signal(&cond);

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
        //      numere[i] = rand();
        //}

        //2.
        fd = open("file.bin", O_RDONLY);
        if(fd == -1)
        {
                perror("open()");
                exit(1);
        }

        pthread_t tp[MAX_THR];
	pthread_t tc[MAX_THR];

        for(int i=0;i<MAX_THR;i++)
        {
                int *idc = malloc(sizeof(int));
		int *idp = malloc(sizeof(int));
                *idc = i;
		*idp = i;
                pthread_create(&tp[i], NULL, produce, idp);
		pthread_create(&tc[i], NULL, consume, idc);
        }
        for(int i=0;i<MAX_THR;i++)
        {
                pthread_join(tp[i], NULL);
		pthread_join(tc[i], NULL);
        }
	printf("Suma: %d", sum);
	close(fd);
	return 0;
}
