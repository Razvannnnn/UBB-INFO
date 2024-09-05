#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>

int pid;

void child_handler(int sig)
{
	printf("Procesul copilului se termina...\n");
	exit(0);
}

void parent_handler(int sig)
{
	printf("Procesul parintelui se termina...\n");
	kill(pid, SIGUSR1);
	wait(0);
	exit(0);
}

void zombie_handler(int sig)
{
	printf("Parintele asteapta ca copilul sa termine...");
	wait(0);
}

int main(int argc, char* argv[])
{
	pid = fork();
	if(pid == -1)
	{
		perror("fork()");
		exit(1);
	}
	if(pid == 0)
	{
		signal(SIGUSR1, child_handler);
		printf("PID Copil:%d, PID Parinte:%d\n", getpid(), getppid());
		while(1)
		{
			printf("Copilul lucreaza...");
			sleep(1);
		}
		exit(0);
	}
	else
	{
		signal(SIGUSR1, parent_handler);
		signal(SIGUSR1, zombie_handler);
		printf("PID Parinte:%d, PID Copil:%d\n", getpid(), pid);
		while(1)
		{
			printf("Parintele lucreaza...\n");
			sleep(2);
		}
	}
	return 0;
}
