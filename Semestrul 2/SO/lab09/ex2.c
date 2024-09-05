#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdio.h>

int main(int argc, char** argv) {
	int n = 10;
	for(int i=2;i<n/2;i++) {
		int pid = fork();
		if(pid == -1) {
			perror("fork()");
			exit(1);
		}
		if(pid == 0) {
			FILE* fd = fopen("numere.txt", "r");
			if(fd == NULL) {
				perror("fopen()");
				exit(1);
			}

			int nr = 0;

			FILE* fd_tmp = fopen("tmp.txt", "w");
                        if(fd_tmp == NULL) {
      	                        perror("fopen()");
                                exit(1);
                        }

			while(fscanf(fd, "%d", &nr) > 0) {
				if(nr%i != 0 || nr == i) {
					fprintf(fd_tmp, "%d ", nr);
				}
			}

			fclose(fd);
			fclose(fd_tmp);
			remove("numere.txt");
			rename("tmp.txt", "numere.txt");
			exit(0);
		}
		wait(NULL);
	}

	return 0;
}
