#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <unistd.h>

int main(int argc, char* argv[])
{
	if(argc != 2)
	{
		perror("Insuficiente argumente!");
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
		if(pid == 0) // copil
		{
			printf("Pid copil:%d, Pid parinte:%d \n", getpid(), getppid());
			exit(0);
		}
		else        // parinte
		{
			printf("Pid parinte: %d, Pid copil:%d \n", getpid(), pid);
		}
	}
	return 0;
}
