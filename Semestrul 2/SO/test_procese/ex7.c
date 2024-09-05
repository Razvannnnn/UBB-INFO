#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <sys/types.h>

int main(int argc, char* argv[])
{
	if(argc != 2)
	{
		perror("Numar invalid de argumente");
		exit(EXIT_FAILURE);
	}

	int pc[2], cp[2];
	int rez = pipe(pc);
	if(rez == -1)
	{
		perror("pipe(pc)");
		exit(EXIT_FAILURE);
	}
	rez = pipe(cp);
	if(rez == -1)
	{
		perror("pipe(cp)");
		exit(EXIT_FAILURE);
	}
	int pid = fork();
	if(pid == -1)
	{
		perror("fork()");
		exit(EXIT_FAILURE);
	}
	if(pid == 0)
	{
		
	}
	else
	{
		close(pc[0]);
		close(cp[1]);
		int n, i, nr;
		printf("N=/d\n", n);
		if(write(pc[1], &n, sizeof(int)) < 0)
		{
			perror("Numar n invalid din parinte");
			close(pc[1]);
			close(cp[0]);
			exit(1);
		}
		for(i=0;i<n;i++)
		{
			if(write(pc[1], &nr, sizeof(int)) < 0)
			{

			}
		}


	}
	return 0;
}
