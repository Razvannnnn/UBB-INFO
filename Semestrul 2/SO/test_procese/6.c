#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>
#include <time.h>

int main(int argc, char* argv[])
{
	if(argc != 2)
	{
		perror("Insuficiente argumente");
		exit(1);
	}

	int p_c[2], c_p[2];
	int rez = pipe(p_c);
	if(rez == -1)
	{
		perror("pipe(p_c)");
		exit(1);
	}
	rez = pipe(c_p);
	if(rez == -1)
	{
		perror("pipe(c_p)");
		exit(1);
	}
	int pid = fork();
	if(pid == -1)
	{
		perror("fork()");
		exit(1);
	}
	if(pid == 0)  //child
	{
		close(p_c[1]);
		close(c_p[0]);
		int n=0, i, nr;
		float rez = 0;
		if(read(p_c[0], &n, sizeof(int)) < 0)
		{
			perror("read()");
			close(p_c[0]);
			close(c_p[1]);
			exit(1);
		}
		for(i=0;i<n;i++)
		{
			if(read(p_c[0], &nr, sizeof(int)) < 0)
			{
				perror("read()");
				close(p_c[0]);
				close(c_p[1]);
				exit(1);
			}
			rez = rez + nr;
		}
		rez = rez/n;
		if(write(c_p[1], &rez, sizeof(float)) < 0)
		{
			perror("write()");
			close(p_c[0]);
			close(c_p[1]);
			exit(1);
		}
		close(p_c[0]);
		close(c_p[1]);
		exit(0);
	}
	else		//parinte
	{
		close(p_c[0]);
		close(c_p[1]);
		int n = atoi(argv[1]);
		int nr, i;
		float rez = -1;
		srandom(time(0));
		if(write(p_c[1], &n, sizeof(int)) < 0)
		{
			perror("write()");
			close(p_c[1]);
			close(c_p[0]);
			exit(1);
		}
		for(i=0;i<n;i++)
		{
			nr = random() % 100;
			if(write(p_c[1], &nr, sizeof(int)) < 0)
			{
				perror("write()");
				close(p_c[1]);
				close(c_p[0]);
				exit(1);
			}
		}
		wait(0);
		if(read(c_p[0], &rez, sizeof(float)) < 0)
		{
			perror("read()");
		}
		printf("Rezultat: %f", rez);
		close(p_c[1]);
		close(c_p[0]);
	}
	return 0;
}
