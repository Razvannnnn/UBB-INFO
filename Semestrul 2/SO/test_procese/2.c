#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <string.h>

int main(int argc, char* argv[])
{
	if(argc != 2)
	{
		perror("Argumente insuficiente");
		exit(1);
	}

	int n = atoi(argv[1]);
	for(int i=0;i<n;i++)
	{
		int pid = fork();
		if(pid == -1)
		{
			perror("fork()");
			exit(1);
		}
		if(pid == 0)
		{
			printf("PID Copil:%d, PID Parinte:%d\n", getpid(), getppid());
		}
		else
		{
			printf("PID Parinte:%d, PID Copil:%d\n", getpid(), pid);
			wait(0);
			exit(0);
		}
	}
	return 0;
}
