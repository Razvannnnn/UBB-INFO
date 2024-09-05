//
// Using fork() to create a child process
//

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>

int main(int argc, char* argv[])
{
    // creez pipe
    int pd[2];
    int res = pipe(pd);
    if(res == -1)
    {
	perror("pipe()");
	exit(EXIT_FAILURE);
    }

    int pid = fork();
    if (pid == -1) // fork() failed
    {
        perror("fork() error: ");
        exit(EXIT_FAILURE);
    }
    if (pid == 0) // in child process
    {
	close(pd[1]);
	int nr1=0, nr2=0;
	read(pd[0], &nr1, sizeof(int));
	read(pd[0], &nr2, sizeof(int));

	int sum = nr1+nr2;

	printf("Suma: %d", &sum);
	close(pd[0]);
	exit(EXIT_FAILURE);
    }
    else // in parent process
    {
	close(pd[0]);
	FILE* file = fopen("numere.txt", "r");

	if(file == NULL)
	{
		perror("fopen()");
		exit(EXIT_FAILURE);
	}
	int nr1=0, nr2=0;
	fscanf(file, "%d %d", &nr1, &nr2);
	fclose(file);

	write(pd[1], &nr1, sizeof(int));
	write(pd[1], &nr2, sizeof(int));

	close(pd[1]);

	int sum=0;
	read(pd[0], &sum, sizeof(int));

	close(pd[0]);
    }
    return 0;
}
