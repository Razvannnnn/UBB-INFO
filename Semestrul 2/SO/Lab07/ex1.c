//
// Using fork() to create a child process
//

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
//#include <sys/types.h>

int main(int argc, char* args[])
{
    int pid = fork();
    if (pid == -1)                      // fork() failed
    {
        perror("fork()");
        exit(EXIT_FAILURE);
    }

    if (pid == 0)                       // in child process
    {
	// creez fisierul de iesire
	int fd = open("file_list", O_CREAT | O_TRUNC | O_RDWR, 0644);
	if(fd == -1)
	{
        	perror("open()");
		exit(EXIT_FAILURE);
	}

	// redirectez iesirea standard
	dup2(fd, STDOUT_FILENO);
	close(fd);

	// execut comanda
	if(execvp(args[0], args) < 0)
	{
		perror("execvp()");
		exit(EXIT_FAILURE);
	}
    }
    else                                // in parent process
    {
        printf("[In PARENT]\tMy PID is %d\tChild PID is %d\n", getpid(), pid);
    }

    return 0;
}
