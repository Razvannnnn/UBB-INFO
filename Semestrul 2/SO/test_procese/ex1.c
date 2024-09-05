#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>


int main()
{
	int n = 5;
	for(int i=0;i<n;i++) {
		int pid = fork();
		if(pid == -1) {
			perror("fork() error:");
		}
		if(pid == 0) {   //child
			printf("Child process: %d - PID: %d - PPID: %d\n", i, getpid(), getppid());
			exit(0);
		}
		else {           //parinte
			printf("Parent %d - Child: %d\n", getpid(), pid);
		}
	}
	for(int i=0;i<=n;i++) {
		wait(NULL);
	}
	return 0;
}
