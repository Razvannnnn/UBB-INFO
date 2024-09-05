#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <pthread.h>


int stop;
pthread_barrier_t barr;
pthread_mutex_t mtx = PTHREAD_MUTEX_INITIALIZER;



void* do_work(void* arg)
{
	int td = *(int*)arg;

	free(arg);

	pthread_barrier_wait(&barr);

	while(1)
	{
		pthread_mutex_lock(&mtx);
		if(stop == 0)
		{
			int n = rand() % 111112;
			printf("Thread-ul: %d, numarul: %d\n",td,n);
			if(n % 1001 == 0)
			{
				stop = 1;
				break;
			}
		}
		else break;
		pthread_mutex_unlock(&mtx);
	}
	pthread_mutex_unlock(&mtx);

	return NULL;
}

int main(int argc, char* argv[])
{
	if(argc != 2)
	{
		printf("Prea putine argumente");
		exit(1);
	}

	int n = atoi(argv[1]);

	srand(time(NULL));

	pthread_barrier_init(&barr, NULL, n);

	pthread_t tid[n];
	for(int i=0;i<n;i++)
	{
		int *id = (int*)malloc(sizeof(int));
		*id = i;
		pthread_create(&tid[i], NULL, do_work, id);
	}
	for(int i=0;i<n;i++)
	{
		pthread_join(tid[i], NULL);
	}
	pthread_barrier_destroy(&barr);

	return 0;
}
