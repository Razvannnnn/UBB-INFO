#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define SIZE 128

int pos;
int count;
char buffer[SIZE + 1];
pthread_cond_t cg = PTHREAD_COND_INITIALIZER;
pthread_cond_t cp = PTHREAD_COND_INITIALIZER;
pthread_mutex_t mtx = PTHREAD_MUTEX_INITIALIZER;


void* generate(void* arg)
{
	while(1)
	{
		char ch = 'a' + (rand() % ('z'-'a'+1));

		pthread_mutex_lock(&mtx);
		if(pos == SIZE)
		{
			pthread_cond_signal(&cp);
			while(pos == SIZE)
			{
				pthread_cond_wait(&cg,&mtx);
			}
		}

		if(count == 0) break;

		buffer[pos] = ch;
		pos++;
		pthread_mutex_unlock(&mtx);
	}
	pthread_mutex_unlock(&mtx);
	return NULL;
}

void* print(void* arg)
{
	while(1)
	{
		pthread_mutex_lock(&mtx);

		if(pos != SIZE) {
			pthread_cond_signal(&cg);
			while(pos != SIZE)
			{
				pthread_cond_wait(&cp,&mtx);
			}
		}
		printf("%s\n", buffer);
		memset(buffer, 0, SIZE);
		pos = 0;
		count--;

		pthread_cond_broadcast(&cg);

		if(count == 0) break;
		pthread_mutex_unlock(&mtx);
	}
	pthread_mutex_unlock(&mtx);
	return NULL;
}


int main(int argc, char* argv[])
{
	if(argc != 3) {
		printf("Prea putine argumente!\n");
		exit(1);
	}

	int N = atoi(argv[1]);
	int M = atoi(argv[2]);

	pos = 0;
	count = M;

	pthread_t tid[N+1];

	for(int i=0;i<N;i++)
	{
		pthread_create(&tid[i], NULL, generate, NULL);
	}
	pthread_create(&tid[N], NULL, print, NULL);

	for(int i=0;i<N;i++)
	{
		pthread_join(tid[i], NULL);
	}

	return 0;
}
