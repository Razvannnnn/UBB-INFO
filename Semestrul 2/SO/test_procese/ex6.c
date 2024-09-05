#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <time.h>
#include <string.h>

int main(int argc, char* argv[])
{
	if(argc != 2)
	{
		perror("Numar invalid de argumente");
		exit(EXIT_FAILURE);
	}

	int p_to_c[2], c_to_p[2];
	int res = pipe(p_to_c);
	if(res == -1)
	{
		perror("pipe()");
		exit(EXIT_FAILURE);
	}
	res = pipe(c_to_p);
	if(res == -1)
	{
		perror("pipe()");
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
		close(p_to_c[1]);
		close(c_to_p[0]);
		int n = 0, nr;
		float rez = 0;
		if(read(p_to_c[0], &n, sizeof(int)) < 0) {
			perror("Eroare la citirea lui n ca argument");
			close(p_to_c[0]);
			close(c_to_p[1]);
			exit(1);
		}
		for(int i=0;i<n;i++) {
			if(read(p_to_c[0], &nr, sizeof(int)) < 0) {
				perror("Eroare la citirea lui nr ca argument");
				close(p_to_c[0]);
				close(c_to_p[1]);
				exit(1);
			}
			rez += nr;
		}
		rez = rez/n;
		if(write(c_to_p[1], &rez, sizeof(float)) < 0) {
			perror("Eroare la scrierea lui rez la parinte");
			close(p_to_c[0]);
			close(c_to_p[1]);
			exit(1);
		}
		close(p_to_c[0]);
		close(c_to_p[1]);
		exit(0);
	}
	else
	{
		close(p_to_c[0]);
		close(c_to_p[1]);
		int n = atoi(argv[1]);
		int i, nr;
		float rez = -1;
		srandom(time(0));
		if(write(p_to_c[1], &n, sizeof(int)) < 0) {
			perror("Eroare la scrierea n in copil");
			close(p_to_c[1]);
			close(c_to_p[0]);
			exit(1);
		}
		for(i=0;i<n;i++) {
			nr = random() % 100;
			printf("Parinte generat %d\n", nr);
			if(write(p_to_c[1], &nr, sizeof(int)) < 0) {
				perror("Eroare la scrierea nr in copil");
				close(p_to_c[1]);
				close(c_to_p[0]);
				exit(1);
			}
		}
		wait(0);
		if(read(c_to_p[0], &rez, sizeof(float)) < 0) {
			perror("Eroare la citirea lui rez din copil");
		}
		printf("Average: %f\n", rez);
		close(p_to_c[1]);
		close(c_to_p[0]);
	}
	return 0;
}
