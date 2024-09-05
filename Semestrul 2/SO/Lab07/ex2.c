//
// Using fork() to create a child process
//

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

//#include <sys/types.h>
 
int main(int argc, char* argv[])
{
    int pid = fork();
    if (pid == -1)                      // fork() failed
    {
        perror("fork() error: ");
        exit(EXIT_FAILURE);
    }

    if (pid == 0)                       // in child process
    {
        int num;
	read(pd[0], &n, sizeof(int));
	printf("[COPIL] am citit %d\n", n);
	close(pd[0]);
	exit(0);
    }
    else                                // in parent process
    {
        close(pd[0]);

	int n=5;
	write(pd[1], &n, sizeof(int));

    }

    return 0;
}
